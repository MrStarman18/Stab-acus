#include <iostream>
/*Developer: Justin T. Alexander
Date: May 21-31, 2022
This program defines all necessary functions used in a game of Stab-acus*/
using namespace std;

class PlayerTurn    //each turn is new instance
{   //Moving should end your turn
    bool hasStabbed = 0, hasMoved = 0;

public:
    void stab(GameBoard g, int player, bool roundOver, int roundWinner);
    void move(GameBoard g, int player);
    bool getStabbed() {return hasStabbed;}
    bool getMoved() {return hasMoved;}
};

class GameBoard
{
    int activePlayer, p1Balls[5]{2}, p2Balls[5]{2}, scores[2]{0};
    std::string abacus[5]{};
public:
    GameBoard();
    void print();

    getp1Balls(int rung) {return p1Balls[rung];}
    setp1Balls(int rung, int value) {p1Balls[rung] = value;}

    getp2Balls(int rung) {return p2Balls[rung];}
    setp2Balls(int rung, int value) {p2Balls[rung] = value;}

    getScore(int player) {return scores[player]}
    addToScore(int player) {scores[player] += 1}
};