echo ------------------------------------------------------------------------------------------ >> vcpkg-info\%1.txt
call e vcpkg-info\%1.txt
vcpkg\vcpkg.exe install %1:x64-windows >> vcpkg-info\%1.txt
ping -n 3 127.0.0.1 > nul
echo ------------------------------------------------------------------------------------------ >> vcpkg-info\%1.txt
dir vcpkg\installed\x64-windows\bin >> vcpkg-info\%1.txt
