#include "cpp_bridge.h"

#include "interact/go_export.h"

#include "logic.h"
extern "C"
{

#define CAST_LOGIC(_p_) reinterpret_cast<ISimpleLogic *>(_p_)
#define CAST_TABLE(_p_) reinterpret_cast<ISimpleTable *>(_p_)
#define CAST_USER(_p_) reinterpret_cast<ISimpleUser *>(_p_)

    Logic *ISimpleLogic_new()
    {
        return new GameLogic();
    }

    void ISimpleLogic_delete(Logic *p)
    {
        auto pp = CAST_LOGIC(p);
        delete pp;
    }

    bool ISimpleLogic_on_create(Logic *p, Table *table, const char *gamerule, int64_t len)
    {
        return CAST_LOGIC(p)->on_create(CAST_TABLE(table), std::string(gamerule, len));
    }
    bool ISimpleLogic_on_reset(Logic *p, const char *gamerule, int64_t len)
    {
        return CAST_LOGIC(p)->on_reset(std::string(gamerule, len));
    }
    bool ISimpleLogic_on_user_enter(Logic *p, User *user, bool bcontinue)
    {
        return CAST_LOGIC(p)->on_user_enter(CAST_USER(user), bcontinue);
    }
    bool ISimpleLogic_on_user_leave(Logic *p, User *user, unsigned char leave_reason)
    {
        return CAST_LOGIC(p)->on_user_leave(CAST_USER(user), leave_reason);
    }
    bool ISimpleLogic_on_user_socketclose(Logic *p, User *user)
    {
        return CAST_LOGIC(p)->on_user_socketclose(CAST_USER(user));
    }
    bool ISimpleLogic_on_socket_message(Logic *p, User *user, int32_t cmdid, int32_t cmd_len, const char *buff)
    {
        return CAST_LOGIC(p)->on_socket_message(CAST_USER(user), cmdid, cmd_len, buff);
    }
    bool ISimpleLogic_on_destory(Logic *p)
    {
        return CAST_LOGIC(p)->on_destory();
    }
}
// bool ISimpleUser_on_sitdown(ISimpleTable *table, unsigned short seat){}
// bool ISimpleUser_on_standup(){}