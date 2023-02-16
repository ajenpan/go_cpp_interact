#ifndef SIMPLE_LOGIC_GAMETABLE_H_
#define SIMPLE_LOGIC_GAMETABLE_H_

#include <vector>
#include <map>
#include "interface.h"
#include "define.h"


class CGameTable : public ISimpleTable{
public:
    CGameTable(int tableid, int gameid, int chairs);
    ~CGameTable();

public:
    
    virtual int get_tableid();
    virtual int get_gameid();
    virtual int get_chairs();
    virtual ISimpleUser* get_user(unsigned short seat);
    virtual bool init_table();
    virtual bool sit_down(ISimpleUser* user);
    virtual bool stand_up(ISimpleUser* user);
    virtual bool on_user_message(ISimpleUser* user, int cmdid, int cmd_len, const char* buff);
    virtual bool reportGameStart(ulong8* uuid);
    virtual bool reportGameEnd();

protected:

    bool has_user(ISimpleUser* user);
    unsigned short get_randseat();

protected:
    
    int     tableid_ = 0;
    int     gameid_ = 0;
    ulong8  uuid_ = 0;
    int     chairs_ = 0;
    ISimpleLogic *logic_ = nullptr;

    std::map<int, ISimpleUser*>  player_list_;

};

#endif
