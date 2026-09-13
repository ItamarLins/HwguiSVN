/*
 * gifwindow.prg
 * Animated GIF 64x64 using TPanel + HTimer + hwg_DrawGifFrame.
 * No HOwnButton, no HBitmap.
 */

#include "hwgui.ch"

#define GIF_PATH   "C:\dev\hwgui\image\hwgui_64x64.gif"
#define GIF_SIZE   64
#define GIF_X      20
#define GIF_Y      20
#define NSPEED     1.0
#define TIMER_ID   33999

/* Window size = GIF area + margins on both sides + border + title bar.
   hwgui window SIZE considers the client area only for MAIN windows,
   so: 64 (GIF) + 20 (left) + 20 (right) = 104 wide
       64 (GIF) + 20 (top)  + 20 (bottom) = 104 tall
   Ajuste os margens abaixo se quiser mais espaço. */
#define WIN_W      104
#define WIN_H      104

STATIC oMain, oPanel, oTimer

FUNCTION Main()

   LOCAL nInterval

   INIT WINDOW oMain MAIN ;
      TITLE "GIF 64x64" ;
      AT 200, 150 SIZE WIN_W, WIN_H

   @ 0, 0 PANEL oPanel OF oMain SIZE WIN_W, WIN_H

   /* Paint callback: draws the auto-animated GIF.
      frame = -1 means auto; last parameter is the speed factor. */
   oPanel:bPaint := {|o, hDC| ;
      IIf( o == Nil, NIL, NIL ), ;
      hwg_DrawGifFrame( hDC, GIF_PATH, ;
                        GIF_X, GIF_Y, GIF_SIZE, GIF_SIZE, ;
                        -1, NSPEED ) }

   /* Timer interval derived from the speed factor.
      Windows timers cannot fire faster than ~16 ms. */
   nInterval := Int( 60 / NSPEED )
   IF nInterval < 16
      nInterval := 16
   ENDIF

   /* HTimer:New() already registers the timer - no Start/Activate.
      Partial invalidation: only the GIF rectangle is repainted. */
   oTimer := HTimer():New( oPanel, TIMER_ID, nInterval, {|| ;
      hwg_InvalidateRect( oPanel:handle, .F., ;
                          GIF_X, GIF_Y, GIF_X + GIF_SIZE, GIF_Y + GIF_SIZE ) } )

   ACTIVATE WINDOW oMain CENTER

   RETURN Nil
