@echo off
REM
REM bcc_comp.bat
REM
REM $Id: bcc_comp.bat 3123 2022-10-02 16:31:29Z df7be $
REM
REM Compile a single C program with Borland C
REM Usage: bcc_comp.bat <C program name with extension .c>
REM
SET BCCINSTDIR=C:\bcc
bcc32 -I%BCCINSTDIR%\include -L%BCCINSTDIR%\lib %1
REM
REM =========================== EOF of bcc_comp.bat ==================================

