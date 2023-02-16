#ifndef SIMPLELOGIC_TEST_H_
#define SIMPLELOGIC_TEST_H_

#include "define.h"
#include "game_table.h"
#include "game_logic.h"
#include "game_user.h"

class CTest{
public:

    CTest();
    ~CTest();

public:

    bool test_game_step();

protected:

    ISimpleTable* table_ = nullptr;
    ISimpleUser*  user_ = nullptr;

    int tableid_;
    int gameid_;
    int chairs_;
    
    int areaid1_ = 5001;
    int numid1_ = 123456;
    std::string nickname1_ = "test123456";

    int areaid2_ = 5001;
    int numid2_ = 123457;
    std::string nickname2_ = "test123457";

};

#endif
