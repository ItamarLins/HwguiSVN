@echo off
REM 
REM build.bat
REM
REM $Id: build.bat 3583 2025-04-13 10:57:36Z josequintas $
REM
REM Build libraries and sample program for 
REM QR encoding feature with the hbmk2 utility
REM
 
REM qrcodegenerator.c to library libqrcodegen.a
hbmk2 qrcodegenerator.hbp
REM Batch sample (static link)
hbmk2 hb_qrencode.hbp
REM qrencode.c and libqrencode.prg to libhbqrencode.a
hbmk2 qrencode.hbp 

REM ================ EOF of build.bat ====================