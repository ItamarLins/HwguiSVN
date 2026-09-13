/*
 * Harbour 3.2.1dev (r2607071005)
 * LLVM/Clang C 22.1.8 (https://github.com/msys2/MINGW-packages 6e4e79c2f86eeb534e
 * Generated C source from "source\winapi\hmisc.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"
#line 31 "source\\winapi\\hmisc.prg"

#include "hbapi.h"

HB_FUNC( HWG_HAS_WIN_EURO_SUPPORT )
{
#ifdef __XHARBOUR__
   hb_retl( 0 );
#else
#if ( HB_VER_REVID - 0 ) >= 2002101634
   hb_retl( 1 );
#else
   hb_retl( 0 );
#endif
#endif
}

