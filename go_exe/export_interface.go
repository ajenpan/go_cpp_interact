package main

/*
#cgo CFLAGS: -I${SRCDIR}/../interact
#cgo LDFLAGS: -Wl,-rpath,${SRCDIR}
#cgo LDFLAGS: -L${SRCDIR} -lcpp_loigc


// #include <dlfcn.h>

#include "../interact/cpp_export.h"

*/
import "C"
import (
	"fmt"
	"unsafe"
)

type SimpleUser struct {
	areaid   int32
	numid    int32
	nickname string
}

type SimpleTable struct {
	tableid int32
}

func (t *SimpleTable) GetTableid() int32 {
	return t.tableid
}

type User interface {
	get_areaid() int32
	get_numid() int32
}

// type Table struct {
// 	get_tableid() int32
// 	get_gameid() int32
// 	get_chairs() int32
// }

//export ISimpleUser_get_areaid
func ISimpleUser_get_areaid(p User) int32 {
	return p.get_areaid()
}

//export ISimpleUser_get_numid
func ISimpleUser_get_numid(p User) int32 {
	return p.get_numid()
}

//export ISimpleTable_get_tableid
func ISimpleTable_get_tableid(t unsafe.Pointer) int32 {
	fmt.Printf("%v\n", t)
	return (*SimpleTable)(t).GetTableid()
	// (*SimpleTable)(t)
	// return 1111
}

// func ISimpleTable_get_gameid(p *C.void);
// func ISimpleTable_get_chairs(p *C.void);
// func ISimpleTable_get_user(p *C.void);

func NewLogic() {
	logic := C.ISimpleLogic_new()

	t := &SimpleTable{
		tableid: 1234567,
	}
	rulestr := "config:hello world"
	crulestr := C.CString(rulestr)

	C.ISimpleLogic_on_create(logic, unsafe.Pointer(t), crulestr, C.int64_t(len(rulestr)))
	C.ISimpleLogic_delete(logic)
	// handle := C.dlopen(C.CString("libcpp_loigc.so"), C.RTLD_LAZY)
	// logic := C.dlsym(handle, C.CString("create_loigc"))

	// table := &SimpleTable{}

	// rule := ""

	// C.ISimpleLogic_on_create(logic, unsafe.Pointer(table), C._GoStringPtr(rule), c._GoStringLen(rule))

	// fmt.Println(logic)
}

// //  ISimpleUser
// int ISimpleUser_get_areaid(ISimpleUser *);
// int ISimpleUser_get_numid(ISimpleUser *);
// unsigned short ISimpleUser_get_seat(ISimpleUser *);
// const char *ISimpleUser_get_nickname(ISimpleUser *);
// bool ISimpleUser_on_sitdown(ISimpleUser *, ISimpleTable *table, unsigned short seat);
// bool ISimpleUser_on_standup(ISimpleUser *);

// // ISimpleTable

// int get_tableid(ISimpleTable *p);
// int get_gameid(ISimpleTable *p);
// int get_chairs(ISimpleTable *p);
// ISimpleUser *get_user(ISimpleTable *p, unsigned short seat);

// // ISimpleLogic

// bool ISimpleLogic_on_create(ISimpleLogic *, ISimpleTable *table, const char *gamerule, long long len);
// bool ISimpleLogic_on_reset(ISimpleLogic *, const char *gamerule, long long len);
// bool ISimpleLogic_on_user_enter(ISimpleLogic *, ISimpleUser *user, bool bcontinue);
// bool ISimpleLogic_on_user_leave(ISimpleLogic *, ISimpleUser *user, unsigned char leave_reason);
// bool ISimpleLogic_on_user_socketclose(ISimpleLogic *, ISimpleUser *user);
// bool ISimpleLogic_on_socket_message(ISimpleLogic *, ISimpleUser *user, int cmdid, int cmd_len, const char *buff);
// bool ISimpleLogic_on_destory(ISimpleLogic *);
