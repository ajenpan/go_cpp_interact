#ifndef __LOGIC_BRIDGE_H__
#define __LOGIC_BRIDGE_H__

#include "interface_define.h"

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct ISimpleUser ISimpleUser;
    typedef struct ISimpleTable ISimpleTable;
    typedef struct ISimpleLogic ISimpleLogic;

    API_PUBLIC ISimpleUser *ISimpleUser_new();
    API_PUBLIC void ISimpleUser_delete(ISimpleUser *);

    API_PUBLIC ISimpleTable *ISimpleTable_new();
    API_PUBLIC void ISimpleTable_delete(ISimpleTable *);

    API_PUBLIC ISimpleLogic *ISimpleLogic_new();
    API_PUBLIC void ISimpleLogic_delete(ISimpleLogic *);

    //  ISimpleUser
    API_PUBLIC int ISimpleUser_get_areaid(ISimpleUser *);
    API_PUBLIC int ISimpleUser_get_numid(ISimpleUser *);
    API_PUBLIC unsigned short ISimpleUser_get_seat(ISimpleUser *);
    API_PUBLIC const char *ISimpleUser_get_nickname(ISimpleUser *);
    API_PUBLIC bool ISimpleUser_on_sitdown(ISimpleUser *, ISimpleTable *table, unsigned short seat);
    API_PUBLIC bool ISimpleUser_on_standup(ISimpleUser *);

    // ISimpleTable

    API_PUBLIC int ISimpleTable_get_tableid(ISimpleTable *p);
    API_PUBLIC int ISimpleTable_get_gameid(ISimpleTable *p);
    API_PUBLIC int ISimpleTable_get_chairs(ISimpleTable *p);
    API_PUBLIC ISimpleUser *ISimpleTable_get_user(ISimpleTable *p, unsigned short seat);

    // ISimpleLogic

    API_PUBLIC bool ISimpleLogic_on_create(ISimpleLogic *, ISimpleTable *table, const char *gamerule, long long len);
    API_PUBLIC bool ISimpleLogic_on_reset(ISimpleLogic *, const char *gamerule, long long len);
    API_PUBLIC bool ISimpleLogic_on_user_enter(ISimpleLogic *, ISimpleUser *user, bool bcontinue);
    API_PUBLIC bool ISimpleLogic_on_user_leave(ISimpleLogic *, ISimpleUser *user, unsigned char leave_reason);
    API_PUBLIC bool ISimpleLogic_on_user_socketclose(ISimpleLogic *, ISimpleUser *user);
    API_PUBLIC bool ISimpleLogic_on_socket_message(ISimpleLogic *, ISimpleUser *user, int cmdid, int cmd_len, const char *buff);
    API_PUBLIC bool ISimpleLogic_on_destory(ISimpleLogic *);

#ifdef __cplusplus
} // extern "C"
#endif
#endif