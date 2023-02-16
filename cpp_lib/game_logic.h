#ifndef SIMPLE_LOGIC_GAMELOGIC_H_
#define SIMPLE_LOGIC_GAMELOGIC_H_

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include "interface.h"
#include "define.h"

class CGameLogic : public ISimpleLogic{
public:
    CGameLogic();
    ~CGameLogic();

public:

    bool on_create(ISimpleTable* table, const std::string& gamerule);
    bool on_reset(const std::string& gamerule);
    bool on_user_enter(ISimpleUser* user, bool bcontinue);
    bool on_user_leave(ISimpleUser* user, unsigned char leave_reason);
    bool on_user_socketclose(ISimpleUser* user);
    bool on_socket_message(ISimpleUser* user, int cmdid, int cmd_len, const char* buff);
    bool on_destory();

protected:

    ISimpleUser* find_user(int areaid, int numid);

protected:
    ISimpleTable* table_ = nullptr;
    std::string gamerule_ = "";
    std::map<long long, ISimpleUser*>  player_list_;
};

#endif
