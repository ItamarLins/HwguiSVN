/*
 * Harbour 3.2.1dev (r2607071005)
 * GNU C 15.3 (64-bit)
 * Generated C source from "source/gtk4/hmisc.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( HWG_HDSERIAL );
HB_FUNC( HWG_HAS_WIN_EURO_SUPPORT );


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HMISC )
{ "HWG_HDSERIAL", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_HDSERIAL )}, NULL },
{ "HWG_HAS_WIN_EURO_SUPPORT", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_HAS_WIN_EURO_SUPPORT )}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HMISC, "source/gtk4/hmisc.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HMISC
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HMISC )
   #include "hbiniseg.h"
#endif

HB_FUNC( HWG_HDSERIAL )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,40,0,106,1,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC( HWG_HAS_WIN_EURO_SUPPORT )
{
	static const HB_BYTE pcode[] =
	{
		36,46,0,120,110,7
	};

	hb_vmExecute( pcode, symbols );
}

