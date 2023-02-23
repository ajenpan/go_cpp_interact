#pragma once

#include <stdint.h>
#include <stdbool.h>

#include "interface_define.h"

#ifdef __cplusplus
extern "C"
{
#endif

    // typedef struct User User;
    // typedef struct ISimpleTable ISimpleTable;
    // typedef struct Logic Logic;

    // API_PUBLIC User *ISimpleUser_new();
    // API_PUBLIC void ISimpleUser_delete(User *);

    // API_PUBLIC ISimpleTable *ISimpleTable_new();
    // API_PUBLIC void ISimpleTable_delete(ISimpleTable *);

    // //  User
    // API_PUBLIC int32_t ISimpleUser_get_areaid(User *);
    // API_PUBLIC int32_t ISimpleUser_get_numid(User *);
    // API_PUBLIC unsigned short ISimpleUser_get_seat(User *);
    // API_PUBLIC const char *ISimpleUser_get_nickname(User *);
    // API_PUBLIC bool ISimpleUser_on_sitdown(User *, ISimpleTable *table, unsigned short seat);
    // API_PUBLIC bool ISimpleUser_on_standup(User *);

    // // ISimpleTable

    // API_PUBLIC int32_t ISimpleTable_get_gameid(ISimpleTable *p);
    // API_PUBLIC int32_t ISimpleTable_get_chairs(ISimpleTable *p);
    // API_PUBLIC User *ISimpleTable_get_user(ISimpleTable *p, unsigned short seat);

    // extern struct ISimpleTable;
    // extern struct User;
    // extern struct Logic;

    // struct Table;
    // struct User;
    // struct Logic;

    typedef void Table;
    typedef void User;
    typedef void Logic;

    extern int32_t ISimpleTable_get_tableid(Table *p);

    // need to impl in logic lib
    API_PUBLIC Logic *ISimpleLogic_new();
    API_PUBLIC void ISimpleLogic_delete(Logic *);

    API_PUBLIC bool ISimpleLogic_on_create(Logic *, Table *table, const char *gamerule, int64_t len);
    API_PUBLIC bool ISimpleLogic_on_reset(Logic *, const char *gamerule, int64_t len);
    API_PUBLIC bool ISimpleLogic_on_user_enter(Logic *, User *user, bool bcontinue);
    API_PUBLIC bool ISimpleLogic_on_user_leave(Logic *, User *user, unsigned char leave_reason);
    API_PUBLIC bool ISimpleLogic_on_user_socketclose(Logic *, User *user);
    API_PUBLIC bool ISimpleLogic_on_socket_message(Logic *, User *user, int32_t cmdid, int32_t cmd_len, const char *buff);
    API_PUBLIC bool ISimpleLogic_on_destory(Logic *);

#ifdef __cplusplus
} // extern "C"
#endif
