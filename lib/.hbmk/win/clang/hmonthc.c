/*
 * Harbour 3.2.1dev (r2607071005)
 * LLVM/Clang C 22.1.8 (https://github.com/msys2/MINGW-packages 6e4e79c2f86eeb534e
 * Generated C source from "source\winapi\hmonthc.prg"
 */

#include "hbvmpub.h"
#include "hbinit.h"


HB_FUNC( HMONTHCALENDAR );
HB_FUNC_EXTERN( __CLSLOCKDEF );
HB_FUNC_EXTERN( HBCLASS );
HB_FUNC_EXTERN( HCONTROL );
HB_FUNC_STATIC( HMONTHCALENDAR_NEW );
HB_FUNC_STATIC( HMONTHCALENDAR_ACTIVATE );
HB_FUNC_STATIC( HMONTHCALENDAR_INIT );
HB_FUNC_STATIC( HMONTHCALENDAR_VALUE );
HB_FUNC_EXTERN( __CLSUNLOCKDEF );
HB_FUNC_EXTERN( __OBJHASMSG );
HB_FUNC_EXTERN( HWG_BITOR );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( DATE );
HB_FUNC_EXTERN( HWG_INITCOMMONCONTROLSEX );
HB_FUNC( HWG_INITMONTHCALENDAR );
HB_FUNC( HWG_SETMONTHCALENDARDATE );
HB_FUNC( HWG_GETMONTHCALENDARDATE );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_HMONTHC )
{ "HMONTHCALENDAR", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( HMONTHCALENDAR )}, NULL },
{ "__CLSLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSLOCKDEF )}, NULL },
{ "NEW", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HBCLASS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HBCLASS )}, NULL },
{ "HCONTROL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HCONTROL )}, NULL },
{ "ADDMULTICLSDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMULTIDATA", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ADDMETHOD", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HMONTHCALENDAR_NEW", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HMONTHCALENDAR_NEW )}, NULL },
{ "HMONTHCALENDAR_ACTIVATE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HMONTHCALENDAR_ACTIVATE )}, NULL },
{ "HMONTHCALENDAR_INIT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HMONTHCALENDAR_INIT )}, NULL },
{ "HMONTHCALENDAR_VALUE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HMONTHCALENDAR_VALUE )}, NULL },
{ "CREATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__CLSUNLOCKDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( __CLSUNLOCKDEF )}, NULL },
{ "INSTANCE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "__OBJHASMSG", {HB_FS_PUBLIC}, {HB_FUNCNAME( __OBJHASMSG )}, NULL },
{ "INITCLASS", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_BITOR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_BITOR )}, NULL },
{ "SUPER", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_DVALUE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VALTYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTYPE )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "DATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( DATE )}, NULL },
{ "_BCHANGE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_INITCOMMONCONTROLSEX", {HB_FS_PUBLIC}, {HB_FUNCNAME( HWG_INITCOMMONCONTROLSEX )}, NULL },
{ "ADDEVENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OPARENT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ID", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "ACTIVATE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "_HANDLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_INITMONTHCALENDAR", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_INITMONTHCALENDAR )}, NULL },
{ "STYLE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NLEFT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NTOP", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NWIDTH", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "NHEIGHT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "INIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "LINIT", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "DVALUE", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "HWG_SETMONTHCALENDARDATE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_SETMONTHCALENDARDATE )}, NULL },
{ "HWG_GETMONTHCALENDARDATE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( HWG_GETMONTHCALENDARDATE )}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_HMONTHC, "source\\winapi\\hmonthc.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_HMONTHC
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_HMONTHC )
   #include "hbiniseg.h"
#endif

HB_FUNC( HMONTHCALENDAR )
{
	static const HB_BYTE pcode[] =
	{
		149,3,0,116,42,0,36,20,0,103,1,0,100,8,
		29,134,1,176,1,0,104,1,0,12,1,29,123,1,
		166,61,1,0,122,80,1,48,2,0,176,3,0,12,
		0,106,15,72,77,111,110,116,104,67,97,108,101,110,
		100,97,114,0,108,4,4,1,0,108,0,112,3,80,
		2,36,22,0,48,5,0,95,2,100,106,14,83,121,
		115,77,111,110,116,104,67,97,108,51,50,0,95,1,
		121,72,121,72,121,72,121,72,106,9,119,105,110,99,
		108,97,115,115,0,4,1,0,9,112,5,73,36,24,
		0,48,6,0,95,2,100,100,95,1,121,72,121,72,
		121,72,106,7,100,86,97,108,117,101,0,4,1,0,
		9,112,5,73,36,25,0,48,6,0,95,2,100,100,
		95,1,121,72,121,72,121,72,106,8,98,67,104,97,
		110,103,101,0,4,1,0,9,112,5,73,36,29,0,
		48,7,0,95,2,106,4,78,101,119,0,108,8,95,
		1,121,72,121,72,121,72,112,3,73,36,30,0,48,
		7,0,95,2,106,9,65,99,116,105,118,97,116,101,
		0,108,9,95,1,121,72,121,72,121,72,112,3,73,
		36,31,0,48,7,0,95,2,106,5,73,110,105,116,
		0,108,10,95,1,121,72,121,72,121,72,112,3,73,
		36,32,0,48,7,0,95,2,106,6,86,97,108,117,
		101,0,108,11,95,1,121,72,121,72,112,3,73,48,
		7,0,95,2,106,7,95,86,97,108,117,101,0,108,
		11,95,1,121,72,121,72,121,72,112,3,73,36,34,
		0,48,12,0,95,2,112,0,73,167,14,0,0,176,
		13,0,104,1,0,95,2,20,2,168,48,14,0,95,
		2,112,0,80,3,176,15,0,95,3,106,10,73,110,
		105,116,67,108,97,115,115,0,12,2,28,12,48,16,
		0,95,3,164,146,1,0,73,95,3,110,7,48,14,
		0,103,1,0,112,0,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HMONTHCALENDAR_NEW )
{
	static const HB_BYTE pcode[] =
	{
		13,0,15,36,40,0,176,17,0,95,4,100,8,28,
		5,121,25,4,95,4,97,0,0,1,0,12,2,80,
		4,36,41,0,96,4,0,95,13,100,8,31,6,95,
		13,31,5,121,25,4,92,16,135,36,42,0,96,4,
		0,95,14,100,8,31,6,95,14,31,5,121,25,4,
		92,8,135,36,43,0,96,4,0,95,15,100,8,31,
		6,95,15,31,5,121,25,4,92,4,135,36,45,0,
		48,2,0,48,18,0,102,112,0,95,1,95,2,95,
		4,95,5,95,6,95,7,95,8,95,9,95,10,100,
		100,95,12,112,12,73,36,47,0,48,19,0,102,176,
		20,0,95,3,12,1,106,2,68,0,8,28,15,176,
		21,0,95,3,12,1,31,6,95,3,25,7,176,22,
		0,12,0,112,1,73,36,49,0,48,23,0,102,95,
		11,112,1,73,36,51,0,176,24,0,20,0,36,53,
		0,95,11,100,69,28,78,36,54,0,48,25,0,48,
		26,0,102,112,0,93,22,253,48,27,0,102,112,0,
		95,11,120,106,9,111,110,67,104,97,110,103,101,0,
		112,5,73,36,55,0,48,25,0,48,26,0,102,112,
		0,93,19,253,48,27,0,102,112,0,95,11,120,106,
		9,111,110,67,104,97,110,103,101,0,112,5,73,36,
		58,0,48,28,0,102,112,0,73,36,60,0,102,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HMONTHCALENDAR_ACTIVATE )
{
	static const HB_BYTE pcode[] =
	{
		36,64,0,176,21,0,48,29,0,48,26,0,102,112,
		0,112,0,12,1,31,74,36,66,0,48,30,0,102,
		176,31,0,48,29,0,48,26,0,102,112,0,112,0,
		48,27,0,102,112,0,48,32,0,102,112,0,48,33,
		0,102,112,0,48,34,0,102,112,0,48,35,0,102,
		112,0,48,36,0,102,112,0,12,7,112,1,73,36,
		67,0,48,37,0,102,112,0,73,36,70,0,100,110,
		7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HMONTHCALENDAR_INIT )
{
	static const HB_BYTE pcode[] =
	{
		36,74,0,48,38,0,102,112,0,31,53,36,75,0,
		48,37,0,48,18,0,102,112,0,112,0,73,36,76,
		0,176,21,0,48,39,0,102,112,0,12,1,31,22,
		36,77,0,176,40,0,48,29,0,102,112,0,48,39,
		0,102,112,0,20,2,36,81,0,100,110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_STATIC( HMONTHCALENDAR_VALUE )
{
	static const HB_BYTE pcode[] =
	{
		13,0,1,36,85,0,95,1,100,69,28,58,36,86,
		0,176,20,0,95,1,12,1,106,2,68,0,8,28,
		62,176,21,0,95,1,12,1,31,53,36,87,0,176,
		40,0,48,29,0,102,112,0,95,1,20,2,36,88,
		0,48,19,0,102,95,1,112,1,73,25,23,36,91,
		0,48,19,0,102,176,41,0,48,29,0,102,112,0,
		12,1,112,1,73,36,93,0,48,39,0,102,112,0,
		110,7
	};

	hb_vmExecute( pcode, symbols );
}

HB_FUNC_INITSTATICS()
{
	static const HB_BYTE pcode[] =
	{
		117,42,0,1,0,7
	};

	hb_vmExecute( pcode, symbols );
}

#line 98 "source\\winapi\\hmonthc.prg"

#define _WIN32_IE      0x0500
#define HB_OS_WIN_32_USED
#ifndef _WIN32_WINNT
   #define _WIN32_WINNT   0x0400
#endif
#include "guilib.h"
#include <windows.h>
#include <commctrl.h>

#include "hbapi.h"
#include "hbapiitm.h"
#include "hbdate.h"

#if defined(__DMC__)
#include "missing.h"
#endif

HB_FUNC( HWG_INITMONTHCALENDAR )
{
   HWND hMC;

   hMC = CreateWindowEx( 0,
                         MONTHCAL_CLASS,
                         TEXT(""),
                         (LONG) hb_parnl(3), /* 0,0,0,0, */
                         hb_parni(4), hb_parni(5),      /* x, y       */
                         hb_parni(6), hb_parni(7),      /* nWidth, nHeight */
                         (HWND) HB_PARHANDLE(1),
                         (HMENU) ( UINT_PTR ) hb_parni(2),
                         GetModuleHandle(NULL),
                         NULL );

   SetWindowPos( hMC, NULL, hb_parni(4), hb_parni(5), hb_parni(6),hb_parni(7), SWP_NOZORDER );

   HB_RETHANDLE(  hMC );
}

HB_FUNC( HWG_SETMONTHCALENDARDATE ) // adaptation of hwg_Setdatepicker of file Control.c
{
   PHB_ITEM pDate = hb_param( 2, HB_IT_DATE );

   if( pDate )
   {
      SYSTEMTIME sysTime;
      #ifndef HARBOUR_OLD_VERSION
      int lYear, lMonth, lDay;
      #else
      long lYear, lMonth, lDay;
      #endif

      hb_dateDecode( hb_itemGetDL( pDate ), &lYear, &lMonth, &lDay );

      sysTime.wYear = (unsigned short) lYear;
      sysTime.wMonth = (unsigned short) lMonth;
      sysTime.wDay = (unsigned short) lDay;
      sysTime.wDayOfWeek = 0;
      sysTime.wHour = 0;
      sysTime.wMinute = 0;
      sysTime.wSecond = 0;
      sysTime.wMilliseconds = 0;

      MonthCal_SetCurSel( (HWND) HB_PARHANDLE (1), &sysTime);

   }
}

HB_FUNC( HWG_GETMONTHCALENDARDATE ) // adaptation of hwg_Getdatepicker of file Control.c
{
   SYSTEMTIME st;
   char szDate[9];

   SendMessage( (HWND) HB_PARHANDLE (1), MCM_GETCURSEL, 0, (LPARAM) &st);

   hb_dateStrPut( szDate, st.wYear, st.wMonth, st.wDay );
   szDate[8] = 0;
   hb_retds( szDate );
}

HB_FUNC( HWG_GETMONTHCALENDARSIZE )
{
   RECT rc;
   PHB_ITEM aMetr = hb_itemArrayNew( 2 );
   PHB_ITEM temp;

   MonthCal_GetMinReqRect( (HWND) HB_PARHANDLE (1), &rc );

   temp = hb_itemPutNL( NULL, rc.right - rc.left );
   hb_itemArrayPut( aMetr, 1, temp );
   hb_itemRelease( temp );

   temp = hb_itemPutNL( NULL, rc.bottom - rc.top );
   hb_itemArrayPut( aMetr, 2, temp );
   hb_itemRelease( temp );

   hb_itemReturn( aMetr );
   hb_itemRelease( aMetr );

}

