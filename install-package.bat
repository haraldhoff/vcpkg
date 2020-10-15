@echo off

if "%cd%" == "C:\opt\vcpkg" goto ok1
echo This vcpkg git repository must be checked out to C:\opt\vcpkg in order to work properly
goto out

:ok1
if not "%1" == "" goto ok2
echo No package specified
goto out

:ok2
if exist "vcpkg.exe" goto ok2:
call bootstrap-vcpkg.bat

:ok3:
echo Installing package %1, logging output to vcpkg-info\%1.txt
echo Please check logfile after build is complete
if not exist "vcpkg-info" mkdir vcpkg-info
vcpkg.exe install %1:x64-windows >> vcpkg-info\%1.txt

:out
