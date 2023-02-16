#ifndef SIMPLE_LOGIC_USER_H_
#define SIMPLE_LOGIC_USER_H_

#include <string>
#include "define.h"
#include "interface.h"


class CGameUser: public ISimpleUser{
public:
    CGameUser(int areaid, int numid, const std::string& nickname);
    ~CGameUser();

    int get_areaid();
    int get_numid();
    unsigned short get_seat();
    std::string get_nickname();
    bool on_sitdown(ISimpleTable* table, unsigned short seat);
    bool on_standup();

protected:
    
    int areaid_ = 0;
    int numid_ = 0;
    std::string nickname_ = "";
    unsigned short seat_ = INVALID_SEAT;
    ISimpleTable* table_;
};

#endif
