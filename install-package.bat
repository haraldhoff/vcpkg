@echo Installing package %1, logging output to vcpkg-info\%1.txt
vcpkg.exe install %1:x64-windows >> vcpkg-info\%1.txt
