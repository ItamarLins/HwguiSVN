
#include "hwgui.ch"
REQUEST HB_CODEPAGE_PTISO

FUNCTION Main()
   LOCAL oMainWnd
   hb_cdpSelect( "PTISO" )

   INIT WINDOW oMainWnd ;
      MAIN ;
      TITLE "RTF File Viewer" ;
      AT 100, 100 ;
      SIZE 1240, 650

   MENU OF oMainWnd
      MENU TITLE "&File"
         MENUITEM "&Open RTF..." ACTION OpenRTFFile( oMainWnd )
         SEPARATOR
         MENUITEM "&Exit"        ACTION hwg_EndWindow()
      ENDMENU
   ENDMENU

   oMainWnd:Activate()

RETURN Nil

FUNCTION OpenRTFFile( oMainWnd )
   LOCAL cFile, oRich := nil
   LOCAL nWinWidth, nWinHeight

   cFile := hwg_Selectfile( { "RTF Files ( *.rtf )" }, { "*.rtf" } )

   IF !Empty( cFile )

      IF Len( oMainWnd:aControls ) > 0
         oMainWnd:aControls[1]:End()
         oMainWnd:aControls := {}
      ENDIF

      nWinWidth  := oMainWnd:nWidth - 30
      nWinHeight := oMainWnd:nHeight - 70

      @ 5, 5 RICHEDIT oRich TEXT "" OF oMainWnd ;
         SIZE nWinWidth, nWinHeight ;
         STYLE WS_VSCROLL + WS_HSCROLL + ES_MULTILINE + ES_AUTOVSCROLL

        HWG_LOADRICHEDIT( oRich:handle, cFile )

        hwg_Redrawwindow( oMainWnd:handle )

   ENDIF

   HB_SYMBOL_UNUSED( nWinWidth )
   HB_SYMBOL_UNUSED( nWinHeight )

RETURN Nil
