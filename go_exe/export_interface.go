package main

/*
#cgo CFLAGS: -I${SRCDIR}/../interact
#cgo LDFLAGS: -Wl,-rpath,${SRCDIR}/../interact
#cgo LDFLAGS: -L${SRCDIR}/../interact
#cgo LDFLAGS: -ldl

#include <dlfcn.h>
#include <stdbool.h>
// #include "logic_bridge.h"
*/
import "C"
import (
	"fmt"
)

type SimpleUser struct {
	areaid   int32
	numid    int32
	nickname string
}

type Table interface {
	get_tableid() int32
	get_gameid() int32
	get_chairs() int32
}

// //export ISimpleUser_get_areaidv2
// func (u *SimpleUser) ISimpleUser_get_areaidv2() int32 {
// 	return u.areaid
// }

//export ISimpleUser_get_areaid
func ISimpleUser_get_areaid(p *C.void) int32 {
	return 0
}

//export ISimpleTable_get_tableid
func ISimpleTable_get_tableid(t Table, p *C.void) int32 {
	return 0
}

// func ISimpleTable_get_gameid(p *C.void);
// func ISimpleTable_get_chairs(p *C.void);
// func ISimpleTable_get_user(p *C.void);

func NewLogic() {
	handle := C.dlopen(C.CString("libfoo.so"), C.RTLD_LAZY)
	logic := C.dlsym(handle, C.CString("create_loigc"))

	fmt.Println(logic)
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
