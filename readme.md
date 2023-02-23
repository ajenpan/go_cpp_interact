# readme

1. 生成golang到处函数
```sh
cd go_exe
go tool cgo -exportheader ../interact/go_export.h ./export_interface.go 
```

2. 编译 cpp logic so

```sh
cd cpp_logic 
mkdir -p build && cd build 
cmake .. && cmake --build .

```

3. 编译 go_exe

```sh
cd go_exe
go build . 
```

4 运行 go_exe

```sh
chmod +x ./go_exe
./go_exe
```