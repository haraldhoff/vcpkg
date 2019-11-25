echo ------------------------------------------------------------------------------------------ >> vcpkg-info\upgrade-%1.txt
call e vcpkg-info\upgrade-%1.txt
vcpkg\vcpkg.exe upgrade --no-dry-run >> vcpkg-info\upgrade-%1.txt
ping -n 3 127.0.0.1 > nul
echo ------------------------------------------------------------------------------------------ >> vcpkg-info\upgrade-%1.txt
dir vcpkg\installed\x64-windows\bin >> vcpkg-info\upgrade-%1.txt
