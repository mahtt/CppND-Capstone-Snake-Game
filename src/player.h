#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player{
    public:
    Player();

    int GetScore() const;
    std::string GetName() const;
    void IncreaseScoreAfterFood();
    void SetPlayerName(std::string name){_name = name;}

    private:
    std::string _name{"-"}; 
    int _score{0};he Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.
};
#endif