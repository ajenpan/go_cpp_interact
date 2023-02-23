
#include "logic.h"

#define logtrace() std::cout << __FUNCTION__ << std::endl

GameLogic::GameLogic()
{
    logtrace();
}

GameLogic::~GameLogic()
{
    logtrace();
}

bool GameLogic::on_create(ISimpleTable *table, const std::string &gamerule)
{
    // std::cout << __FUNCTION__ << ",table=" << table << ",tableid=" << table->get_tableid() << ",gamerule=" << gamerule << std::endl;
    logtrace();

    table_ = table;
    gamerule_ = gamerule;
    return true;
}

bool GameLogic::on_reset(const std::string &gamerule)
{
    //  std::cout << __FUNCTION__ << ",table=" << table_ << ",gamerule=" << gamerule << std::endl;
    logtrace();
    gamerule_ = gamerule;
    return true;
}

bool GameLogic::on_user_enter(ISimpleUser *user, bool bcontinue)
{
    logtrace();
    if (!user)
        return false;

    // std::cout << __FUNCTION__ << ",table=" << table_<<",tableid=" <<table_->get_tableid() << ",user=" << user \
    // <<",aid=" <<user->get_areaid() <<",nid=" <<user->get_numid() <<",nickname=" << user->get_nickname() << std::endl;

    // ulong8 id = MAKE_COMUSRID(user->get_areaid(), user->get_numid());
    // auto cur_user = find_user(user->get_areaid(), user->get_numid());
    // if (!cur_user){
    //     player_list_[id] = user;
    // }

    // if (player_list_.size() == table_->get_chairs()){
    //     ulong8 uuid;
    //     table_->reportGameStart(&uuid);
    // }

    return true;
}

bool GameLogic::on_user_leave(ISimpleUser *user, unsigned char leave_reason)
{
    logtrace();
    if (!user)
        return false;

    // std::cout << __FUNCTION__ << ",table=" << table_ << ",tableid=" << table_->get_tableid() << ",user=" << user \
    //     << ",aid=" << user->get_areaid() << ",nid=" << user->get_numid() << ",nickname=" << user->get_nickname() << std::endl;

    // auto id = MAKE_COMUSRID(user->get_areaid(), user->get_numid());
    // player_list_.erase(id);

    // if (player_list_.empty()){
    //     table_->reportGameEnd();
    // }

    return true;
}

bool GameLogic::on_user_socketclose(ISimpleUser *user)
{
    logtrace();
    if (!user)
        return false;
    //std::cout << __FUNCTION__ << ",table=" << table_ << ",tableid=" << table_->get_tableid() << ",user=" << user \
    //    << ",aid=" << user->get_areaid() << ",nid=" << user->get_numid() << ",nickname=" << user->get_nickname() << std::endl;

    return true;
}

bool GameLogic::on_socket_message(ISimpleUser *user, int cmdid, int cmd_len, const char *buff)
{
    logtrace();
    if (!user)
        return false;
    //std::cout << __FUNCTION__ << ", user=" << user << ",areaid=" << user->get_areaid() << ",numid=" << user->get_numid()\
    //<<",cmdid=" <<cmdid <<",cmdlen:" <<cmd_len << std::endl;

    return true;
}

bool GameLogic::on_destory()
{
    logtrace();
    // std::cout << __FUNCTION__ << ", table=" << table_ << ",this=" << this << std::endl;
    return true;
}

ISimpleUser *GameLogic::find_user(int areaid, int numid)
{
    logtrace();
    // ulong8 id = MAKE_COMUSRID(areaid, numid);
    //  return player_list_.find(id) != player_list_.end() ? player_list_[id]:nullptr;
    return nullptr;
}
