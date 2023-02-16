#include "game_table.h"
#include "game_logic.h"
#include <iostream>

CGameTable::CGameTable(int tableid, int gameid, int chairs) :tableid_(tableid), gameid_(gameid),chairs_(chairs){
    
    logic_ = new CGameLogic();
}

CGameTable::~CGameTable(){
    if (logic_){
        delete logic_;
    }
    logic_ = nullptr;
}

bool CGameTable::init_table(){
    std::cout << __FUNCTION__ <<",tableid=" <<tableid_ <<std::endl;

    if (logic_){
        logic_->on_create(this, "gameid=1001;chairs=4;");
    }
    return true;
}



int CGameTable::get_tableid(){
    return tableid_;
}

int CGameTable::get_gameid(){
    return gameid_;
}

int CGameTable::get_chairs(){
    return chairs_;
}

unsigned short CGameTable::get_randseat(){
    for (int i = 0; i < chairs_; i++){
       auto cur_user = get_user(i);
       if (!cur_user){
           return i;
       }
    }

    return INVALID_SEAT;
}

bool CGameTable::sit_down(ISimpleUser* user){
    if (!user) return false;

    std::cout << __FUNCTION__ << ", tableid = " << tableid_ << ", user = " << user << ", aid = " << user->get_areaid() << ", nid = " <<user->get_numid()\
        << ",nickname=" << user->get_nickname() << std::endl;

    auto has = has_user(user);
    if (has){
        return false;
    }
    auto cur_seat = get_randseat();
    player_list_[cur_seat] = user;
    user->on_sitdown(this, cur_seat);

    if (logic_){
        logic_->on_user_enter(user, false);
    }
    return true;
}

bool CGameTable::stand_up(ISimpleUser* user){
    if (!user) return false;
    
    std::cout << __FUNCTION__ << ", tableid=" << tableid_ << ",user=" << user << ",aid=" << user->get_areaid() << ",nid=" << user->get_numid()\
        << ",nickname=" << user->get_nickname() << std::endl;
    
    if (!has_user(user)){
        return false;
    }

    player_list_.erase(user->get_seat());

    if (logic_){
        logic_->on_user_leave(user, 0);
    }
    return true;
}

bool CGameTable::on_user_message(ISimpleUser* user, int cmdid, int cmd_len, const char* buff){
    if (!user) return false;

    std::cout << __FUNCTION__ << ",tableid = " << tableid_ << ", user = " << user << ", aid = " << user->get_areaid() << ", nid = " << user->get_numid()\
    <<",nickname=" <<user->get_nickname() <<",cmdid=" <<cmdid <<",cmd_len=" <<cmd_len << std::endl;

    if (logic_){
        logic_->on_socket_message(user, cmdid, cmd_len, buff);
    }
    return true;
}

ISimpleUser* CGameTable::get_user(unsigned short seat){
    return player_list_.find(seat) != player_list_.end() ? player_list_[seat]:nullptr;
}

bool CGameTable::has_user(ISimpleUser* user){
    for (auto &it : player_list_){
        if ( it.second->get_areaid() == user->get_areaid() && it.second->get_numid() == user->get_numid() ){
            return true;
        }
    }
    return false;
}

bool CGameTable::reportGameStart(ulong8* uuid){
    *uuid = 12345678;
    uuid_ = *uuid;
    std::cout << __FUNCTION__ << ", tableid = " << tableid_ << ", uuid = " << *uuid << std::endl;
    return true;    
}

bool CGameTable::reportGameEnd(){
    std::cout << __FUNCTION__ << ", tableid = " << tableid_ << std::endl;

    return true;
}
