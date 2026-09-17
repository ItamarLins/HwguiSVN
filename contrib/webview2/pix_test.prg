#include "hwgui.ch"
#include "hbdyn.ch"

STATIC pLib     := NIL
STATIC hWebView := NIL

//=============================================================================
FUNCTION Main()
   LOCAL oForm

   hb_cdpSelect( "UTF8" )

   pLib := hb_LibLoad( "webview_wrapper.dll" )
   IF pLib == NIL
      hwg_MsgStop( "Falhou hb_LibLoad" )
      RETURN NIL
   ENDIF

   INIT WINDOW oForm TITLE "HwguiTurbo - Gerador PIX" SIZE 900, 750 ;
      ON INIT { || InicializaWebView( oForm ) } ;
      ON EXIT { || FinalizaWebView() }

   MENU OF oForm
      MENU TITLE "&Arquivo"
         MENUITEM "Sai&r" ACTION oForm:Close()
      ENDMENU
      MENU TITLE "A&juda"
         MENUITEM "&Sobre..." ACTION hwg_MsgInfo( "HwguiTurbo - Gerador PIX v1.0" )
      ENDMENU
   ENDMENU

   oForm:bOther := { |o, msg, wp, lp| OnOtherMsg( o, msg, wp, lp ) }

   ACTIVATE WINDOW oForm CENTER

   IF pLib != NIL
      hb_LibFree( pLib )
   ENDIF
RETURN NIL

//=============================================================================
STATIC FUNCTION OnOtherMsg( o, nMsg, nWParam, nLParam )
   IF nMsg == 1124
      CheckMensagem()
      RETURN 0
   ENDIF
RETURN -1

//=============================================================================
STATIC FUNCTION InicializaWebView( oForm )
   LOCAL nBind

   hWebView := hb_DynCall( { "create_webview_embedded", pLib, ;
                             hb_bitOr( HB_DYN_CTYPE_VOID_PTR, HB_DYN_CALLCONV_CDECL ), ;
                             HB_DYN_CTYPE_CHAR_PTR, ;
                             HB_DYN_CTYPE_CHAR_PTR, ;
                             HB_DYN_CTYPE_INT, ;
                             HB_DYN_CTYPE_INT }, ;
                           "HwguiTurbo - Gerador PIX", "WebView2", 900, 710 )

   IF hWebView == NIL
      hwg_MsgStop( "Nao criou WebView" )
      RETURN NIL
   ENDIF

   nBind := BindJS( "ExecutarAcao" )
   IF nBind != 0
      hwg_MsgStop( "bind falhou: " + hb_ValToStr( nBind ) )
   ENDIF

   hb_DynCall( { "navigate_webview", pLib, ;
                 hb_bitOr( HB_DYN_CTYPE_VOID, HB_DYN_CALLCONV_CDECL ), ;
                 HB_DYN_CTYPE_VOID_PTR, ;
                 HB_DYN_CTYPE_CHAR_PTR }, ;
               hWebView, "file:///"+hb_DirBase()+"/pix.html" )
RETURN NIL

//=============================================================================
STATIC FUNCTION BindJS( cName )
RETURN hb_DynCall( { "bind_webview", pLib, ;
                     hb_bitOr( HB_DYN_CTYPE_INT, HB_DYN_CALLCONV_CDECL ), ;
                     HB_DYN_CTYPE_VOID_PTR, ;
                     HB_DYN_CTYPE_CHAR_PTR }, ;
                   hWebView, cName )

//=============================================================================
STATIC FUNCTION CheckMensagem()
   LOCAL cId, cJson, cFunc, cResult

   IF hWebView == NIL
      RETURN NIL
   ENDIF

   cId := hb_DynCall( { "get_message_id", pLib, ;
                        hb_bitOr( HB_DYN_CTYPE_CHAR_PTR, HB_DYN_CALLCONV_CDECL ) } )
   IF ValType( cId ) == "A" .AND. Len( cId ) >= 1
      cId := cId[1]
   ENDIF
   IF cId == NIL .OR. Empty( cId )
      RETURN NIL
   ENDIF

   cFunc := hb_DynCall( { "get_message_func", pLib, ;
                          hb_bitOr( HB_DYN_CTYPE_CHAR_PTR, HB_DYN_CALLCONV_CDECL ) } )
   IF ValType( cFunc ) == "A" .AND. Len( cFunc ) >= 1
      cFunc := cFunc[1]
   ENDIF

   cJson := hb_DynCall( { "get_message_data", pLib, ;
                          hb_bitOr( HB_DYN_CTYPE_CHAR_PTR, HB_DYN_CALLCONV_CDECL ) } )
   IF ValType( cJson ) == "A" .AND. Len( cJson ) >= 1
      cJson := cJson[1]
   ENDIF

   cResult := Despachar( cFunc, cJson )

   hb_DynCall( { "reply_webview", pLib, ;
                 hb_bitOr( HB_DYN_CTYPE_INT, HB_DYN_CALLCONV_CDECL ), ;
                 HB_DYN_CTYPE_VOID_PTR, ;
                 HB_DYN_CTYPE_CHAR_PTR }, ;
               hWebView, cResult )
RETURN NIL

//=============================================================================
STATIC FUNCTION Despachar( cFunc, cJson )
   LOCAL hParams, cAcao, hArgs

   HB_SYMBOL_UNUSED( cFunc )

   hParams := hb_jsonDecode( cJson )
   IF ValType( hParams ) == "A" .AND. Len( hParams ) >= 1
      hParams := hParams[1]
   ENDIF
   IF ValType( hParams ) != "H"
      hParams := {=>}
   ENDIF

   cAcao := hb_HGetDef( hParams, "acao", "" )
   hArgs := hb_HGetDef( hParams, "args", {=>} )
   IF ValType( hArgs ) != "H"
      hArgs := {=>}
   ENDIF

   DO CASE
   CASE cAcao == "pix.gerar"
      RETURN GerarPix( hArgs )
   ENDCASE

RETURN hb_jsonEncode( { "ok" => .F., "msg" => "Acao desconhecida: " + cAcao } )

//=============================================================================
// Gera o PIX (função chamada do JavaScript)
//=============================================================================
STATIC FUNCTION GerarPix( hArgs )
   LOCAL cChave  := AllTrim( hb_HGetDef( hArgs, "chave",     "" ) )
   LOCAL nValor  := hb_HGetDef( hArgs, "valor", 0 )
   LOCAL cNome   := AllTrim( hb_HGetDef( hArgs, "nome",      "" ) )
   LOCAL cCidade := AllTrim( hb_HGetDef( hArgs, "cidade",    "" ) )
   LOCAL cTxID   := AllTrim( hb_HGetDef( hArgs, "txid",      "" ) )
   LOCAL cDesc   := AllTrim( hb_HGetDef( hArgs, "descricao", "" ) )
   LOCAL cPix

   // Validacoes
   IF Empty( cChave )
      RETURN hb_jsonEncode( { "ok" => .F., "msg" => "Chave PIX obrigatoria" } )
   ENDIF
   IF nValor <= 0
      RETURN hb_jsonEncode( { "ok" => .F., "msg" => "Valor deve ser maior que zero" } )
   ENDIF
   IF Empty( cNome )
      RETURN hb_jsonEncode( { "ok" => .F., "msg" => "Nome do recebedor obrigatorio" } )
   ENDIF
   IF Empty( cCidade )
      RETURN hb_jsonEncode( { "ok" => .F., "msg" => "Cidade obrigatoria" } )
   ENDIF

   // Aplica limites do BACEN
   IF Len( cChave )  > 77
      cChave  := Left( cChave,  77 )
   ENDIF
   IF Len( cNome )   > 25
      cNome   := Left( cNome,   25 )
   ENDIF
   IF Len( cCidade ) > 15
      cCidade := Left( cCidade, 15 )
   ENDIF
   IF Empty( cTxID )
      cTxID := "***"
   ENDIF
   IF Len( cTxID )   > 25
      cTxID   := Left( cTxID,   25 )
   ENDIF
   IF Len( cDesc )   > 70
      cDesc   := Left( cDesc,   70 )
   ENDIF

   cPix := GerarPixEstatico( cChave, nValor, cNome, cCidade, cTxID, cDesc )

RETURN hb_jsonEncode( { "ok" => .T., "pix" => cPix, "valor" => nValor } )

//=============================================================================
// Gera o BR Code (Pix Estatico)
//=============================================================================
STATIC FUNCTION GerarPixEstatico( cChave, nValor, cNome, cCidade, cTxID, cDesc )
   LOCAL cPayload    := ""
   LOCAL cSubMerchant := ""
   LOCAL cValorStr
   LOCAL cTxIDTag

   // Converte valor para string com ponto decimal e 2 casas
   // Ex: 10 -> "10.00" ; 1234.5 -> "1234.50"
   cValorStr := AllTrim( Str( nValor, 13, 2 ) )

   // Tag 00: Payload Format Indicator
   cPayload += "000201"

   // Tag 01: Point of Initiation Method (12 = uso unico, 11 = reutilizavel)
   cPayload += "010212"

   // Tag 26: Merchant Account Information
   cSubMerchant := "0014br.gov.bcb.pix" + "01" + StrZero( Len( cChave ), 2 ) + cChave
   IF !Empty( cDesc )
      cSubMerchant += "02" + StrZero( Len( cDesc ), 2 ) + cDesc
   ENDIF
   cPayload += "26" + StrZero( Len( cSubMerchant ), 2 ) + cSubMerchant

   // Tag 52: Merchant Category Code
   cPayload += "52040000"

   // Tag 53: Transaction Currency (986 = BRL)
   cPayload += "5303986"

   // Tag 54: Transaction Amount
   cPayload += "54" + StrZero( Len( cValorStr ), 2 ) + cValorStr

   // Tag 58: Country Code
   cPayload += "5802BR"

   // Tag 59: Merchant Name
   cPayload += "59" + StrZero( Len( cNome ), 2 ) + cNome

   // Tag 60: Merchant City
   cPayload += "60" + StrZero( Len( cCidade ), 2 ) + cCidade

   // Tag 62: Additional Data Field (TxID)
   cTxIDTag := "05" + StrZero( Len( cTxID ), 2 ) + cTxID
   cPayload += "62" + StrZero( Len( cTxIDTag ), 2 ) + cTxIDTag

   // Tag 63: CRC16
   cPayload += "6304"
   cPayload += CalcularCRC16( cPayload )

RETURN cPayload

//=============================================================================
// CRC16-CCITT (XMODEM) exigido pelo BACEN
//=============================================================================
STATIC FUNCTION CalcularCRC16( cTexto )
   LOCAL nCRC     := 65535
   LOCAL nPolynom := 4129
   LOCAL x, j, nBit, nC

   FOR x := 1 TO Len( cTexto )
      nC := Asc( SubStr( cTexto, x, 1 ) )
      nCRC := hb_bitXor( nCRC, hb_bitShift( nC, 8 ) )

      FOR j := 1 TO 8
         IF hb_bitAnd( nCRC, 32768 ) != 0
            nCRC := hb_bitXor( hb_bitShift( nCRC, 1 ), nPolynom )
         ELSE
            nCRC := hb_bitShift( nCRC, 1 )
         ENDIF
         nCRC := hb_bitAnd( nCRC, 65535 )
      NEXT
   NEXT

RETURN Upper( NumToHex( nCRC, 4 ) )

//=============================================================================
STATIC FUNCTION NumToHex( nNum, nLen )
   LOCAL cHex := HB_NumToHex( nNum )
RETURN PadL( AllTrim( cHex ), nLen, "0" )

//=============================================================================
STATIC FUNCTION FinalizaWebView()
   IF hWebView != NIL
      hb_DynCall( { "destroy_webview", pLib, ;
                    hb_bitOr( HB_DYN_CTYPE_VOID, HB_DYN_CALLCONV_CDECL ), ;
                    HB_DYN_CTYPE_VOID_PTR }, ;
                  hWebView )
      hWebView := NIL
   ENDIF
RETURN NIL
