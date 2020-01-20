
@echo off
if "%VCPKG_ROOT%"== ""
(
  echo VCPKG_ROOT not set, using default C:\opt\vcpkg
  set VCPKG_ROOT=C:\opt\vcpkg
)

cmake -G "Visual Studio 15 2017" -A x64 -S . -B build
