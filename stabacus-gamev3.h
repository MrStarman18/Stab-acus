#include <iostream>
/*Developer: Justin T. Alexander
Date: May 21-31, 2022
This program defines all necessary functions used in a game of Stab-acus*/
using namespace std;

class GameBoard //created once then used all game
{
    int activePlayer, p1Balls[5]{2}, p2Balls[5]{2}, scores[2]{0};
    std::string abacus[5]{};
public:
    GameBoard();
    void setupBoard();
    void print(std::string when, int player);

    int getp1Balls(int rung);
    void setp1Balls(int rung, int value);

    int getp2Balls(int rung);
    void setp2Balls(int rung, int value);

    int getScore(int player);
    void addToScore(int player);
};

class PlayerTurn    //each turn is new instance
{   //Moving should end your turn
    bool hasStabbed = 0, hasMoved = 0;

public:
    void stab(GameBoard& g, int player, bool& roundOver, int& roundWinner);
    void move(GameBoard& g, int player);
    bool getStabbed();
    bool getMoved();
};
