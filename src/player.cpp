#include "player.h"
#include <iostream>

Player::Player(){
    //_name = AskPlayerForName();
}



int Player::GetScore() const {return _score;}
std::string Player::GetName() const {return _name;}

void Player::IncreaseScoreAfterFood() { ++_score;}