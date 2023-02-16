#include "logic_bridge.h"
#include "logic_interface.h"

extern "C"
{

    // ISimpleUser *ISimpleUser_new()
    // {
    // }

    // void ISimpleUser_delete(ISimpleUser *p)
    // {
    // }

    int ISimpleUser_get_areaid(ISimpleUser *p)
    {
        return p->get_areaid();
    }

    int ISimpleUser_get_numid(ISimpleUser *p)
    {
        return p->get_numid();
    }

    unsigned short ISimpleUser_get_seat(ISimpleUser *p)
    {
        return p->get_seat();
    }

    const char *ISimpleUser_get_nickname(ISimpleUser *p)
    {
        auto nickname = p->get_nickname();
        return nickname.c_str();
    }

    bool ISimpleUser_on_sitdown(ISimpleUser *p, ISimpleTable *table, unsigned short seat)
    {
        return p->on_sitdown(table, seat);
    }

    bool ISimpleUser_on_standup(ISimpleUser *p)
    {
        return p->on_standup();
    }

    int ISimpleTable_get_tableid(ISimpleTable *p)
    {
        return p->get_tableid();
    }
    int ISimpleTable_get_gameid(ISimpleTable *p)
    {
        return p->get_gameid();
    }
    int ISimpleTable_get_chairs(ISimpleTable *p)
    {
        return p->get_chairs();
    }

    ISimpleUser *ISimpleTable_get_user(ISimpleTable *p, unsigned short seat)
    {
        return p->get_user(seat);
    }

    bool ISimpleLogic_on_create(ISimpleLogic *p, ISimpleTable *table, const char *gamerule, size_t len)
    {
        p->on_create(table, std::string(gamerule, len));
    }
    bool ISimpleLogic_on_reset(ISimpleLogic *p, const char *gamerule, size_t len)
    {
        p->on_reset(std::string(gamerule, len));
    }
    bool ISimpleLogic_on_user_enter(ISimpleLogic *p, ISimpleUser *user, bool bcontinue)
    {
        p->on_user_enter(user, bcontinue);
    }
    bool ISimpleLogic_on_user_leave(ISimpleLogic *p, ISimpleUser *user, unsigned char leave_reason)
    {
        p->on_user_leave(user, leave_reason);
    }
    bool ISimpleLogic_on_user_socketclose(ISimpleLogic *p, ISimpleUser *user)
    {
        p->on_user_socketclose(user);
    }
    bool ISimpleLogic_on_socket_message(ISimpleLogic *p, ISimpleUser *user, int cmdid, int cmd_len, const char *buff)
    {
        p->on_socket_message(user, cmdid, cmd_len, buff);
    }
    bool ISimpleLogic_on_destory(ISimpleLogic *p)
    {
        p->on_destory();
    }
}
// bool ISimpleUser_on_sitdown(ISimpleTable *table, unsigned short seat){}
// bool ISimpleUser_on_standup(){}