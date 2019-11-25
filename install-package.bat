@echo off
echo Installing package %1, logging output to vcpkg-info\%1.txt
echo Please check logfile after build is complete
mkdir vcpkg-info
vcpkg.exe install %1:x64-windows >> vcpkg-info\%1.txt
