#include "player.h"
#include <iostream>

Player::Player(){
    //_name = AskPlayerForName();
}

std::string Player::AskPlayerForName(){
  std::string name;
  std::cout << "What is your name? ";
  std::cin >> name;
  return name;
}


int Player::GetScore() const {return _score;}
std::string Player::GetName() const {return _name;}

void Player::IncreaseScoreAfterFood() { ++_score;}