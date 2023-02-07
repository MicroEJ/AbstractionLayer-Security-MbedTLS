 REM Copyright 2021-2023 MicroEJ Corp. All rights reserved.
 REM Use of this source code is governed by a BSD-style license that can be found with this software.


REM Select the CPPCHECK platform kind, see %CPPCHECK_EXE_DIR%\platforms (typical for ARM-Cortex: arm32-wchar_t2.xml)
SET PLATFORM=arm32-wchar_t2.xml

REM Set the C project to analyse
SET CPROJECT= %~dp0src\main\c

REM Set a report title
SET REPORT_TITLE=bsp-security-mbedtls
