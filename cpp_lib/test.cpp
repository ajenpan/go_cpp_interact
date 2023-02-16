#include "test.h"

CTest::CTest(){

    tableid_ = 1;
    gameid_ = 3001;
    chairs_ = 2;
}

CTest::~CTest(){
    if (table_){
        delete table_;
    }
    table_ = nullptr;
}

bool CTest::test_game_step(){
    
    // add table
    if (!table_){
        table_ = new CGameTable(tableid_, gameid_, chairs_);
    }
    table_->init_table();
    
    // add user
    ISimpleUser* user1 = new CGameUser(areaid1_, numid1_, nickname1_);
    table_->sit_down(user1);

    ISimpleUser* user2 = new CGameUser(areaid2_, numid2_, nickname2_);
    table_->sit_down(user2);

    // add message
    int cmdid1 = 1001;
    std::string buff1 = nickname1_ +":doaction.";
    table_->on_user_message(user1, cmdid1, buff1.length(), buff1.c_str());

    std::string buff2 = nickname2_ + ":doaction.";
    table_->on_user_message(user2, cmdid1, buff2.length(), buff2.c_str());

    // leave user
    table_->stand_up(user1);
    table_->stand_up(user2);

    // free table
    delete table_;
    table_ = nullptr;

    return  true;
}
