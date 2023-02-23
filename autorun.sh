#!/bin/sh

workdir=`pwd`
logicdir=${workdir}/cpp_loigc
exedir=${workdir}/go_exe

cd ${exedir}
go tool cgo -exportheader ../interact/go_export.h ./export_interface.go 

cd ${logicdir}
rm -rf build && mkdir -p build && cd build 
cmake .. && cmake --build .

cd ${exedir}
go build . 
chmod +x ./go_exe
./go_exe