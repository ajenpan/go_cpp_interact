#include "game_user.h"
#include <iostream>

CGameUser::CGameUser(int areaid, int numid, const std::string& nickname):areaid_(areaid),numid_(numid),nickname_(nickname){
    std::cout << "CGameUser, aid=" << areaid << ",nid=" << numid <<",nickname=" << nickname << std::endl;
}

CGameUser::~CGameUser(){

}

int CGameUser::get_areaid(){
    return areaid_;
}

int CGameUser::get_numid(){
    return numid_;
}

unsigned short CGameUser::get_seat(){
    return seat_;
}

std::string CGameUser::get_nickname(){
    return nickname_;
}

bool CGameUser::on_sitdown(ISimpleTable* table, unsigned short seat){
    std::cout << "CGameUser::on_sitdown, tid=" <<table->get_tableid() <<",table=" << table <<",seat=" <<(int)seat << std::endl;
    table = table_;
    seat_ = seat;
    return true;
}

bool CGameUser::on_standup(){
    if (!table_) return false;

    std::cout << "CGameUser::on_standup, tid=" << table_->get_tableid() << ",table=" << table_ << std::endl;
    table_ = nullptr;
    seat_ = INVALID_SEAT;
    return true;
}

