#include "hwgui.ch"
#include "hbdyn.ch"

STATIC pLib       := NIL
STATIC hWebView   := NIL
STATIC nWebViewID := 1

//=============================================================================
FUNCTION Main()
   LOCAL oForm

   hb_cdpSelect( "UTF8" )

   // Create the DBF if it does not exist yet
   IF !File( "clientes.dbf" )
      DbCreate( "clientes.dbf", { ;
         { "NOME",  "C",  60, 0 }, ;
         { "EMAIL", "C",  80, 0 } } )
   ENDIF

   pLib := hb_LibLoad( "webview_wrapper.dll" )
   IF pLib == NIL
      hwg_MsgStop( "hb_LibLoad failed" )
      RETURN NIL
   ENDIF

   INIT WINDOW oForm TITLE "HwguiTurbo - Client Manager" SIZE 900, 700 ;
      ON INIT { || InitWebView( oForm ) } ;
      ON EXIT { || CloseWebView() }

   MENU OF oForm
      MENU TITLE "&File"
         MENUITEM "E&xit" ACTION oForm:Close()
      ENDMENU
      MENU TITLE "&Help"
         MENUITEM "&About..." ACTION hwg_MsgInfo( "HwguiTurbo v1.2.0" )
      ENDMENU
   ENDMENU

   // Capture WM_USER+100 sent by C via PostMessage
   oForm:bOther := { |o, msg, wp, lp| OnOtherMsg( o, msg, wp, lp ) }

   ACTIVATE WINDOW oForm CENTER

   IF pLib != NIL
      hb_LibFree( pLib )
   ENDIF
RETURN NIL

//=============================================================================
STATIC FUNCTION OnOtherMsg( o, nMsg, nWParam, nLParam )
   // WM_USER = 0x0400 = 1024 ; WM_USER+100 = 1124
   IF nMsg == 1124
      CheckMessage()
      RETURN 0
   ENDIF
RETURN -1

//=============================================================================
STATIC FUNCTION InitWebView( oForm )
   LOCAL nBind

   hWebView := hb_DynCall( { "create_webview_embedded", pLib, ;
                             hb_bitOr( HB_DYN_CTYPE_VOID_PTR, HB_DYN_CALLCONV_CDECL ), ;
                             HB_DYN_CTYPE_CHAR_PTR, ;
                             HB_DYN_CTYPE_CHAR_PTR, ;
                             HB_DYN_CTYPE_INT, ;
                             HB_DYN_CTYPE_INT, ;
                             HB_DYN_CTYPE_INT }, ;
                           "HwguiTurbo - Client Manager", "WebView2", 900, 660, ;
                           nWebViewID )

   IF hWebView == NIL
      hwg_MsgStop( "Failed to create WebView" )
      RETURN NIL
   ENDIF

   // Single bind - all actions go through this one
   nBind := BindJS( "ExecutarAcao" )
   IF nBind != 0
      hwg_MsgStop( "bind failed: " + hb_ValToStr( nBind ) )
   ENDIF

   hb_DynCall( { "navigate_webview", pLib, ;
                 hb_bitOr( HB_DYN_CTYPE_VOID, HB_DYN_CALLCONV_CDECL ), ;
                 HB_DYN_CTYPE_VOID_PTR, ;
                 HB_DYN_CTYPE_CHAR_PTR }, ;
               hWebView, "file:///"+hb_dirbase()+"client.html" )
RETURN NIL

//=============================================================================
STATIC FUNCTION BindJS( cName )
RETURN hb_DynCall( { "bind_webview", pLib, ;
                     hb_bitOr( HB_DYN_CTYPE_INT, HB_DYN_CALLCONV_CDECL ), ;
                     HB_DYN_CTYPE_VOID_PTR, ;
                     HB_DYN_CTYPE_CHAR_PTR }, ;
                   hWebView, cName )

//=============================================================================
STATIC FUNCTION EvalJS( cJs )
RETURN hb_DynCall( { "eval_webview", pLib, ;
                     hb_bitOr( HB_DYN_CTYPE_INT, HB_DYN_CALLCONV_CDECL ), ;
                     HB_DYN_CTYPE_VOID_PTR, ;
                     HB_DYN_CTYPE_CHAR_PTR }, ;
                   hWebView, cJs )

//=============================================================================
STATIC FUNCTION CheckMessage()
   LOCAL hCtx, cId, cJson, cFunc, cResult

   IF hWebView == NIL
      RETURN NIL
   ENDIF

   // Single WebView for now: fixed context ID = 1
   hCtx := hb_DynCall( { "get_context_by_id", pLib, ;
                         hb_bitOr( HB_DYN_CTYPE_VOID_PTR, HB_DYN_CALLCONV_CDECL ), ;
                         HB_DYN_CTYPE_INT }, nWebViewID )

   IF hCtx == NIL
      hwg_MsgStop( "Context not found" )
      RETURN NIL
   ENDIF

   cId := hb_DynCall( { "get_message_id", pLib, ;
                        hb_bitOr( HB_DYN_CTYPE_CHAR_PTR, HB_DYN_CALLCONV_CDECL ), ;
                        HB_DYN_CTYPE_VOID_PTR }, hCtx )
   IF ValType( cId ) == "A" .AND. Len( cId ) >= 1
      cId := cId[1]
   ENDIF
   IF cId == NIL .OR. Empty( cId )
      RETURN NIL
   ENDIF

   cFunc := hb_DynCall( { "get_message_func", pLib, ;
                          hb_bitOr( HB_DYN_CTYPE_CHAR_PTR, HB_DYN_CALLCONV_CDECL ), ;
                          HB_DYN_CTYPE_VOID_PTR }, hCtx )
   IF ValType( cFunc ) == "A" .AND. Len( cFunc ) >= 1
      cFunc := cFunc[1]
   ENDIF

   cJson := hb_DynCall( { "get_message_data", pLib, ;
                          hb_bitOr( HB_DYN_CTYPE_CHAR_PTR, HB_DYN_CALLCONV_CDECL ), ;
                          HB_DYN_CTYPE_VOID_PTR }, hCtx )
   IF ValType( cJson ) == "A" .AND. Len( cJson ) >= 1
      cJson := cJson[1]
   ENDIF

   cResult := Dispatch( cFunc, cJson )

   hb_DynCall( { "reply_webview", pLib, ;
                 hb_bitOr( HB_DYN_CTYPE_INT, HB_DYN_CALLCONV_CDECL ), ;
                 HB_DYN_CTYPE_VOID_PTR, ;
                 HB_DYN_CTYPE_CHAR_PTR }, ;
               hCtx, cResult )
RETURN NIL

//=============================================================================
STATIC FUNCTION Dispatch( cFunc, cJson )
   LOCAL hParams, cAction, hArgs

   HB_SYMBOL_UNUSED( cFunc )

   hParams := hb_jsonDecode( cJson )
   IF ValType( hParams ) == "A" .AND. Len( hParams ) >= 1
      hParams := hParams[1]
   ENDIF
   IF ValType( hParams ) != "H"
      hParams := {=>}
   ENDIF

   cAction := hb_HGetDef( hParams, "acao", "" )
   hArgs   := hb_HGetDef( hParams, "args", {=>} )
   IF ValType( hArgs ) != "H"
      hArgs := {=>}
   ENDIF

   DO CASE
   CASE cAction == "cliente.gravar"
      RETURN SaveClient( hArgs )
   CASE cAction == "cliente.listar"
      RETURN ListClients( hArgs )
   CASE cAction == "cliente.apagar"
      RETURN DeleteClient( hArgs )
   CASE cAction == "cliente.buscar"
      RETURN SearchClient( hArgs )
   CASE cAction == "cliente.resumo"
      RETURN SummaryClients()
   CASE cAction == "demo.contar"
      RETURN DemoCount( hArgs )
   ENDCASE

RETURN hb_jsonEncode( { "ok" => .F., "msg" => "Unknown action: " + cAction } )

//=============================================================================
STATIC FUNCTION SaveClient( hData )
   LOCAL cName  := hb_HGetDef( hData, "nome",  "" )
   LOCAL cEmail := hb_HGetDef( hData, "email", "" )
   LOCAL nRecno

   IF Empty( cName )
      RETURN hb_jsonEncode( { "ok" => .F., "msg" => "Name is required" } )
   ENDIF

   OpenClients()

   clients->( DbAppend() )
   REPLACE clients->NOME  WITH cName
   REPLACE clients->EMAIL WITH cEmail
   nRecno := clients->( RecNo() )
   clients->( DbCommit() )

RETURN hb_jsonEncode( { "ok" => .T., "recno" => nRecno } )

//=============================================================================
STATIC FUNCTION ListClients( hData )
   LOCAL nPage       := hb_HGetDef( hData, "pagina",     1 )
   LOCAL nPerPage    := hb_HGetDef( hData, "por_pagina", 50 )
   LOCAL aList       := {}
   LOCAL nTotal      := 0
   LOCAL nTotalPages := 0
   LOCAL nSkip
   LOCAL i

   nPage    := IIF( nPage    < 1, 1,  nPage    )
   nPerPage := IIF( nPerPage < 1, 50, nPerPage )

   OpenClients()

   // Count the total (including deleted)
   clients->( DbGoTop() )
   DO WHILE !clients->( Eof() )
      nTotal++
      clients->( DbSkip() )
   ENDDO

   nTotalPages := Int( ( nTotal + nPerPage - 1 ) / nPerPage )
   IF nTotalPages < 1
      nTotalPages := 1
   ENDIF
   IF nPage > nTotalPages
      nPage := nTotalPages
   ENDIF

   nSkip := ( nPage - 1 ) * nPerPage
   clients->( DbGoTop() )
   IF nSkip > 0
      clients->( DbSkip( nSkip ) )
   ENDIF

   i := 0
   DO WHILE !clients->( Eof() ) .AND. i < nPerPage
      AAdd( aList, { "recno"   => clients->( RecNo() ), ;
                     "nome"    => AllTrim( clients->NOME ), ;
                     "email"   => AllTrim( clients->EMAIL ), ;
                     "deleted" => clients->( Deleted() ) } )
      clients->( DbSkip() )
      i++
   ENDDO

RETURN hb_jsonEncode( { "ok"         => .T., ;
                        "clientes"   => aList, ;
                        "pagina"     => nPage, ;
                        "por_pagina" => nPerPage, ;
                        "total"      => nTotal, ;
                        "total_pag"  => nTotalPages } )

//=============================================================================
STATIC FUNCTION DeleteClient( hData )
   LOCAL nRecno := hb_HGetDef( hData, "recno", 0 )

   IF nRecno <= 0
      RETURN hb_jsonEncode( { "ok" => .F., "msg" => "Invalid RECNO" } )
   ENDIF

   OpenClients()
   clients->( DbGoTo( nRecno ) )
   IF !clients->( Eof() )
      IF clients->( Deleted() )
         clients->( DbRecall() )      // restore
      ELSE
         clients->( DbDelete() )      // mark as deleted
      ENDIF
      clients->( DbCommit() )
      RETURN hb_jsonEncode( { "ok" => .T. } )
   ENDIF

RETURN hb_jsonEncode( { "ok" => .F., "msg" => "Record not found" } )

//=============================================================================
STATIC FUNCTION SearchClient( hData )
   LOCAL cName       := hb_HGetDef( hData, "nome",       "" )
   LOCAL nPage       := hb_HGetDef( hData, "pagina",     1 )
   LOCAL nPerPage    := hb_HGetDef( hData, "por_pagina", 50 )
   LOCAL aList       := {}
   LOCAL aMatches    := {}
   LOCAL nTotal      := 0
   LOCAL nTotalPages := 0
   LOCAL nSkip
   LOCAL i
   LOCAL nIdx

   nPage    := IIF( nPage    < 1, 1,  nPage    )
   nPerPage := IIF( nPerPage < 1, 50, nPerPage )

   OpenClients()

   // Collect matching RECNOs
   clients->( DbGoTop() )
   DO WHILE !clients->( Eof() )
      IF Upper( cName ) $ Upper( AllTrim( clients->NOME ) )
         AAdd( aMatches, clients->( RecNo() ) )
      ENDIF
      clients->( DbSkip() )
   ENDDO

   nTotal := Len( aMatches )
   nTotalPages := Int( ( nTotal + nPerPage - 1 ) / nPerPage )
   IF nTotalPages < 1
      nTotalPages := 1
   ENDIF
   IF nPage > nTotalPages
      nPage := nTotalPages
   ENDIF

   nSkip := ( nPage - 1 ) * nPerPage

   FOR i := 1 TO nPerPage
      nIdx := nSkip + i
      IF nIdx > nTotal
         EXIT
      ENDIF
      clients->( DbGoTo( aMatches[ nIdx ] ) )
      AAdd( aList, { "recno"   => clients->( RecNo() ), ;
                     "nome"    => AllTrim( clients->NOME ), ;
                     "email"   => AllTrim( clients->EMAIL ), ;
                     "deleted" => clients->( Deleted() ) } )
   NEXT

RETURN hb_jsonEncode( { "ok"         => .T., ;
                        "clientes"   => aList, ;
                        "pagina"     => nPage, ;
                        "por_pagina" => nPerPage, ;
                        "total"      => nTotal, ;
                        "total_pag"  => nTotalPages } )

//=============================================================================
STATIC FUNCTION SummaryClients()
   LOCAL nActive   := 0
   LOCAL nDeleted  := 0
   LOCAL nWithMail := 0
   LOCAL nLastRec  := 0
   LOCAL nRecno

   OpenClients()
   clients->( DbGoTop() )
   DO WHILE !clients->( Eof() )
      nRecno := clients->( RecNo() )
      IF nRecno > nLastRec
         nLastRec := nRecno
      ENDIF
      IF clients->( Deleted() )
         nDeleted++
      ELSE
         nActive++
         IF !Empty( AllTrim( clients->EMAIL ) )
            nWithMail++
         ENDIF
      ENDIF
      clients->( DbSkip() )
   ENDDO

RETURN hb_jsonEncode( { "ok"           => .T., ;
                        "ativos"       => nActive, ;
                        "deletados"    => nDeleted, ;
                        "com_email"    => nWithMail, ;
                        "ultimo_recno" => nLastRec } )

//=============================================================================
// DEMO CALLBACK - Harbour loops and calls back the JS at each iteration
//=============================================================================
STATIC FUNCTION DemoCount( hData )
   LOCAL cCallbackId := hb_HGetDef( hData, "callbackId", "" )
   LOCAL nTotal      := hb_HGetDef( hData, "total", 10 )
   LOCAL i, cJs, nPct

   IF Empty( cCallbackId )
      RETURN hb_jsonEncode( { "ok" => .F., "msg" => "callbackId missing" } )
   ENDIF

   FOR i := 1 TO nTotal
      // Simulate work - replace with real processing
      hb_idleSleep( 0.3 )

      nPct := Int( i * 100 / nTotal )

      // Call the JavaScript callback registered by the client
      cJs := "window._hwgui.invoke('" + cCallbackId + "', " + ;
             hb_NToS( nPct ) + ")"
      EvalJS( cJs )
   NEXT

RETURN hb_jsonEncode( { "ok" => .T. } )

//=============================================================================
STATIC FUNCTION OpenClients()
   IF !Used()
      IF !File( "clientes.dbf" )
         DbCreate( "clientes.dbf", { ;
            { "NOME",  "C",  60, 0 }, ;
            { "EMAIL", "C",  80, 0 } } )
      ENDIF
      USE clientes.dbf ALIAS clients NEW
   ENDIF
RETURN NIL

//=============================================================================
STATIC FUNCTION CloseWebView()
   IF hWebView != NIL
      hb_DynCall( { "destroy_webview", pLib, ;
                    hb_bitOr( HB_DYN_CTYPE_VOID, HB_DYN_CALLCONV_CDECL ), ;
                    HB_DYN_CTYPE_VOID_PTR }, ;
                  hWebView )
      hWebView := NIL
   ENDIF
RETURN NIL
