/*
 * Harbour 3.2.1dev (r2607071005)
 * GNU C 15.3 (64-bit)
 * Generated C source from "source/gtk4/herrsys.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( HWG_ERRSYS );
HB_FUNC_EXTERN( ERRORBLOCK );
HB_FUNC_STATIC( DEFERROR );
HB_FUNC_EXTERN( CURDIR );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC( HWG_NATIVEERRORSHOW );
HB_FUNC_EXTERN( NETERR );
HB_FUNC( HWG_ERRMSG );
HB_FUNC_EXTERN( LTRIM );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( HWG_TRACE );
HB_FUNC_EXTERN( HWG_VERSION );
HB_FUNC_EXTERN( DTOC );
HB_FUNC_EXTERN( DATE );
HB_FUNC_EXTERN( TIME );
HB_FUNC_EXTERN( HWG_RELEASETIMERS );
HB_FUNC_EXTERN( MEMOWRIT );
HB_FUNC_EXTERN( HB_ISSTRING );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC( HWG_WRITELOG );
HB_FUNC_EXTERN( FILE );
HB_FUNC_EXTERN( FCREATE );
HB_FUNC_EXTERN( FOPEN );
HB_FUNC_EXTERN( FSEEK );
HB_FUNC_EXTERN( FWRITE );
HB_FUNC_EXTERN( FCLOSE );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HERRSYS )
{ "HWG_ERRSYS", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_ERRSYS )}, NULL },
{ "ERRORBLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( ERRORBLOCK )}, NULL },
{ "DEFERROR", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( DEFERROR )}, NULL },
{ "CURDIR", {HB_FS_PUBLIC}, {HB_FUNCNAME( CURDIR )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "HWG_NATIVEERRORSHOW", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_NATIVEERRORSHOW )}, NULL },
{ "GENCODE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OSCODE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "CANDEFAULT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NETERR", {HB_FS_PUBLIC}, {HB_FUNCNAME( NETERR )}, NULL },
{ "HWG_ERRMSG", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_ERRMSG )}, NULL },
{ "LTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( LTRIM )}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "HWG_TRACE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_TRACE )}, NULL },
{ "HWG_VERSION", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_VERSION )}, NULL },
{ "DTOC", {HB_FS_PUBLIC}, {HB_FUNCNAME( DTOC )}, NULL },
{ "DATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( DATE )}, NULL },
{ "TIME", {HB_FS_PUBLIC}, {HB_FUNCNAME( TIME )}, NULL },
{ "HWG_RELEASETIMERS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_RELEASETIMERS )}, NULL },
{ "MEMOWRIT", {HB_FS_PUBLIC}, {HB_FUNCNAME( MEMOWRIT )}, NULL },
{ "SEVERITY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HB_ISSTRING", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_ISSTRING )}, NULL },
{ "SUBSYSTEM", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VALTYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTYPE )}, NULL },
{ "SUBCODE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DESCRIPTION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "FILENAME", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPERATION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_WRITELOG", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_WRITELOG )}, NULL },
{ "FILE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FILE )}, NULL },
{ "FCREATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FCREATE )}, NULL },
{ "FOPEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( FOPEN )}, NULL },
{ "FSEEK", {HB_FS_PUBLIC}, {HB_FUNCNAME( FSEEK )}, NULL },
{ "FWRITE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FWRITE )}, NULL },
{ "FCLOSE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FCLOSE )}, NULL },
{ "(_INITSTATICS00002)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HERRSYS, "source/gtk4/herrsys.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HERRSYS
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HERRSYS )
   #include "hbiniseg.h"
#endif

HB_FUNC( HWG_ERRSYS )
{
	static const HB_BYTE pcode[] =
	{
		116,35,0,36,35,0,176,1,0,89,15,0,1,0,
		0,0,176,2,0,95,1,12,1,6,20,1,36,36,
		0,106,2,47,0,176,3,0,12,0,72,176,4,0,
		176,3,0,12,0,12,1,28,7,106,1,0,25,6,
		106,2,47,0,72,82,1,0,36,37,0,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( DEFERROR )
{
	static const HB_BYTE pcode[] =
	{
		13,2,1,116,35,0,36,44,0,103,2,0,28,84,
		36,45,0,176,1,0,90,4,100,6,20,1,36,46,
		0,176,5,0,106,54,70,97,116,97,108,58,32,82,
		101,99,117,114,115,105,118,101,32,101,114,114,111,114,
		32,108,111,111,112,32,100,101,116,101,99,116,101,100,
		32,105,110,115,105,100,101,32,69,114,114,111,114,83,
		121,115,46,0,20,1,36,47,0,9,110,7,36,49,
		0,120,82,2,0,36,50,0,176,1,0,90,4,100,
		6,20,1,36,53,0,48,6,0,95,1,112,0,92,
		5,8,28,38,36,54,0,9,82,2,0,36,55,0,
		176,1,0,89,15,0,1,0,0,0,176,2,0,95,
		1,12,1,6,20,1,36,56,0,121,110,7,36,60,
		0,48,6,0,95,1,112,0,92,21,8,28,68,48,
		7,0,95,1,112,0,92,32,8,28,56,48,8,0,
		95,1,112,0,28,47,36,61,0,176,9,0,120,20,
		1,36,62,0,9,82,2,0,36,63,0,176,1,0,
		89,15,0,1,0,0,0,176,2,0,95,1,12,1,
		6,20,1,36,64,0,9,110,7,36,68,0,48,6,
		0,95,1,112,0,92,40,8,28,56,48,8,0,95,
		1,112,0,28,47,36,69,0,176,9,0,120,20,1,
		36,70,0,9,82,2,0,36,71,0,176,1,0,89,
		15,0,1,0,0,0,176,2,0,95,1,12,1,6,
		20,1,36,72,0,9,110,7,36,75,0,176,10,0,
		95,1,12,1,80,2,36,76,0,176,4,0,48,7,
		0,95,1,112,0,12,1,31,58,36,77,0,106,12,
		40,68,79,83,32,69,114,114,111,114,32,0,176,11,
		0,176,12,0,48,7,0,95,1,112,0,12,1,12,
		1,72,106,2,41,0,72,80,3,36,78,0,96,2,
		0,106,2,32,0,95,3,72,135,36,81,0,96,2,
		0,176,13,0,12,0,135,36,82,0,96,2,0,106,
		5,13,10,13,10,0,176,14,0,12,0,72,135,36,
		83,0,96,2,0,106,8,13,10,68,97,116,101,58,
		0,176,15,0,176,16,0,12,0,12,1,72,135,36,
		84,0,96,2,0,106,8,13,10,84,105,109,101,58,
		0,176,17,0,12,0,72,135,36,86,0,176,18,0,
		20,0,36,87,0,176,19,0,103,1,0,106,10,69,
		114,114,111,114,46,108,111,103,0,72,95,2,20,2,
		36,94,0,176,5,0,95,2,20,1,36,96,0,9,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_ERRMSG )
{
	static const HB_BYTE pcode[] =
	{
		13,1,1,36,100,0,48,20,0,95,1,112,0,122,
		15,28,12,106,6,69,114,114,111,114,0,25,12,106,
		8,87,97,114,110,105,110,103,0,106,2,32,0,72,
		80,2,36,101,0,176,21,0,48,22,0,95,1,112,
		0,12,1,28,18,36,102,0,96,2,0,48,22,0,
		95,1,112,0,135,25,15,36,104,0,96,2,0,106,
		4,63,63,63,0,135,36,106,0,176,23,0,48,24,
		0,95,1,112,0,12,1,106,2,78,0,8,28,33,
		36,107,0,96,2,0,106,2,47,0,176,11,0,176,
		12,0,48,24,0,95,1,112,0,12,1,12,1,72,
		135,25,16,36,109,0,96,2,0,106,5,47,63,63,
		63,0,135,36,111,0,176,21,0,48,25,0,95,1,
		112,0,12,1,28,22,36,112,0,96,2,0,106,3,
		32,32,0,48,25,0,95,1,112,0,72,135,36,115,
		0,176,4,0,48,26,0,95,1,112,0,12,1,31,
		24,36,116,0,96,2,0,106,3,58,32,0,48,26,
		0,95,1,112,0,72,135,25,39,36,117,0,176,4,
		0,48,27,0,95,1,112,0,12,1,31,22,36,118,
		0,96,2,0,106,3,58,32,0,48,27,0,95,1,
		112,0,72,135,36,120,0,95,2,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_WRITELOG )
{
	static const HB_BYTE pcode[] =
	{
		13,1,2,116,35,0,36,124,0,103,1,0,95,2,
		100,8,28,12,106,6,97,46,108,111,103,0,25,4,
		95,2,72,80,2,36,125,0,176,29,0,95,2,12,
		1,31,16,36,126,0,176,30,0,95,2,12,1,80,
		3,25,15,36,128,0,176,31,0,95,2,122,12,2,
		80,3,36,130,0,176,32,0,95,3,121,92,2,20,
		3,36,131,0,176,33,0,95,3,95,1,106,2,10,
		0,72,20,2,36,132,0,176,34,0,95,3,20,1,
		36,133,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,35,0,2,0,116,35,0,106,1,0,82,1,0,
		9,82,2,0,7
	};

	hb_vmExecute( pcode, symbols );
}

#line 136 "source/gtk4/herrsys.prg"
/*
   FIXED: Including guilib.h guarantees that the global GCC diagnostics
   and the incomp_pointer.h protections apply to this module as well.
*/
#include "guilib.h"
#include "hbapi.h"
#include <unistd.h> /* Required for _exit() */

#ifdef HB_DEPRECATED
   #undef HB_DEPRECATED
#endif
#include <gtk/gtk.h>

/*
 * GTK4 callback: fired when the dialog receives a close request, which
 * happens when any GtkMessageDialog button is pressed OR when the user
 * clicks the window's X button.
 *
 * GTK4 removed GtkDialog::response — close-request is the new entry
 * point for "the user dismissed this dialog".
 *
 * _exit(0) bypasses atexit handlers and the Harbour engine, exactly as
 * the original implementation did.  It is marked noreturn so GCC does
 * not warn about the missing return.
 */
static gboolean native_kill_callback( GtkWindow *window, gpointer data )
{
   (void)window;
   (void)data;

   /* Absolute hardware-level exit bypasses all pending GTK/Harbour events */
   _exit( 0 );

   return FALSE; /* unreachable */
}

HB_FUNC( HWG_NATIVEERRORSHOW )
{
   const char *acMessage = hb_parc( 1 );

   if( acMessage )
   {
      GtkWidget *pDialog;

      /*
       * GTK4: GTK_DIALOG_DESTROY_WITH_PARENT is deprecated (4.10); the
       * destroy-with-parent behaviour is now the default.  We only pass
       * GTK_DIALOG_MODAL.
       */
      pDialog = gtk_message_dialog_new( NULL,
                                        GTK_DIALOG_MODAL,
                                        GTK_MESSAGE_ERROR,
                                        GTK_BUTTONS_CLOSE,
                                        "%s", acMessage );

      gtk_window_set_title( GTK_WINDOW( pDialog ),
                            "HwGUI - Critical Engine Exception" );

      /*
       * SUPREME BLINDAGE: connect close-request (GTK4 replacement for
       * the removed "response" signal) to our killer callback.  The
       * exact millisecond any button or the window close icon is
       * pressed, the application terminates inside C, avoiding the
       * broken Harbour engine loop.
       */
      g_signal_connect( pDialog, "close-request",
                        G_CALLBACK( native_kill_callback ), NULL );

      /*
       * GTK4: gtk_widget_show_all() was removed.  gtk_window_present()
       * handles both showing the dialog and giving it focus.
       */
      gtk_window_present( GTK_WINDOW( pDialog ) );

      /*
       * Run a clean, isolated iteration loop to hold the window visible.
       * GTK4: gtk_main_iteration() was removed; g_main_context_iteration()
       * is the equivalent primitive.
       *
       * The loop normally never terminates on its own: the close-request
       * handler calls _exit(0) as soon as the user dismisses the dialog.
       */
      while( gtk_widget_get_visible( pDialog ) )
      {
         g_main_context_iteration( NULL, TRUE );
      }
   }
}

