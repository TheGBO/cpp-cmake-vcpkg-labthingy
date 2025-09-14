cmake . && make
mkdir -p build
mv ./Application build
cd build
chmod +x ./Application
./Application