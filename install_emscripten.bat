@echo off
echo make sure you have git installed
echo https://git-scm.com/downloads

cd C:\
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk.bat install latest
./emsdk.bat activate latest --permanent
pause