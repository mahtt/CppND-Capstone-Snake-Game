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
    int _score{0};

    //std::string AskPlayerForName();
};
#endif