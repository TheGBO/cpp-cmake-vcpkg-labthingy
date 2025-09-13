#for windows cross-compiling
cd $HOME/vcpkg
./vcpkg install fmt:community/x64-windows-mingw
./vcpkg install raylib:community/x64-windows-mingw

# for linux compiling
cd $HOME/vcpkg
./vcpkg install fmt
./vcpkg install raylib