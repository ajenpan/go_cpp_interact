#pragma once

#include <string>
#include "interact/cpp_export.h"

class ISimpleUser;
class ISimpleTable;
class ISimpleLogic;

class ISimpleUser
{
public:
    virtual ~ISimpleUser() {}
    virtual int get_areaid() = 0;
    virtual int get_numid() = 0;
    virtual unsigned short get_seat() = 0;
    virtual std::string get_nickname() = 0;
    virtual bool on_sitdown(ISimpleTable *table, unsigned short seat) = 0;
    virtual bool on_standup() = 0;
};

class ISimpleTable
{
public:
    virtual ~ISimpleTable() {}

    virtual int get_tableid() = 0;
    virtual int get_gameid() = 0;
    virtual int get_chairs() = 0;
    virtual ISimpleUser *get_user(unsigned short seat) = 0;
    virtual bool init_table() = 0;
    virtual bool sit_down(ISimpleUser *user) = 0;
    virtual bool stand_up(ISimpleUser *user) = 0;
    virtual bool on_user_message(ISimpleUser *user, int cmdid, int cmd_len, const char *buff) = 0;

    virtual bool reportGameStart(int64_t uuid) = 0;
    virtual bool reportGameEnd() = 0;
};

class ISimpleLogic
{
public:
    virtual ~ISimpleLogic() {}

    virtual bool on_create(ISimpleTable *table, const std::string &gamerule) = 0;
    virtual bool on_reset(const std::string &gamerule) = 0;
    virtual bool on_user_enter(ISimpleUser *user, bool bcontinue) = 0;
    virtual bool on_user_leave(ISimpleUser *user, unsigned char leave_reason) = 0;
    virtual bool on_user_socketclose(ISimpleUser *user) = 0;
    virtual bool on_socket_message(ISimpleUser *user, int cmdid, int cmd_len, const char *buff) = 0;
    virtual bool on_destory() = 0;
};