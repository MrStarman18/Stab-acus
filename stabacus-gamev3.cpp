#include <iostream>
#include "hosttext.h"
#include "stabacus-game.h"
/*Developer: Justin T. Alexander
Date: May 21-31, 2022
This program implements all necessary functions used in a game of Stab-acus*/
//NOTE: PlayerTurn comes before GameBoard here, even though it comes after in the .h
using namespace std;

void PlayerTurn::stab(GameBoard& g, int player, bool& roundOver, int& roundWinner)
{
    int on;
    if (hasStabbed == false)
    {
        g.print("stab", player);
        while (hasStabbed == false)
        {    
            cout << "Stab using one ball on rung __:\nOn rung: ";
            cin >> on;  //expecting rung 1--rung 5
            if (on > 5 || on < 1)
            {
                cout << "Please input rungs on the board (1-5).\n";
                continue;
            }

            if (player == 0 && g.getp1Balls(on - 1) == 0)
                cout << "No ball in rung " << on << "to Stab with!\n";
            else if (player == 1 && g.getp2Balls(on - 1) == 0)
                cout << "No ball in rung " << on << "to Stab with!\n";
            else
            {
                if (player == 0) //successful 1 Stab non-empty rung
                {    
                    if (g.getp2Balls(on - 1) >= 0)
                    {
                        g.setp2Balls(on, g.getp2Balls(on) - 1);
                        cout << stabText();
                        hasStabbed = true;
                    }
                }
                else if (player == 1) //successful p2 Stab non-empty rung
                {    
                    if (g.getp1Balls(on - 1) >= 0)
                    {
                        g.setp1Balls(on, g.getp1Balls(on) - 1);
                        cout << stabText();
                        hasStabbed = true;
                    }    
                }
                else    //balls == 0 when stabbed, ending round
                {
                    roundOver = true;
                    roundWinner = player;   //used to influence hosttext & score
                    hasStabbed = true;
                }
            }
        }
    }
}
void PlayerTurn::move(GameBoard& g, int player)
{   //can't move after stabbing
    int from, to;
    if (hasMoved == false)
    {
        g.print("move", player);
        while (hasMoved == false)
        {
            cout << "Move one ball from rung __ to rung __:\nFrom rung: ";
            cin >> from;
            cout << "to rung: ";
            cin >> to;
            
            if (from > 5 || from < 1 || to > 5 || to < 1)
            {
                cout << "Please input rungs on the board (1-5).\n";
                continue;
            }
            if (player == 0 && g.getp1Balls(from - 1) == 0)
                cout << "No ball in rung " << from << "to move!\n";
            else if (player == 1 && g.getp2Balls(from - 1) == 0)
                cout << "No ball in rung " << from << "to move!\n";
            else if ((g.getp1Balls(to) + g.getp2Balls(to)) >= 15)
                cout << "No room on rung " << to << "for another ball!\n";
            else 
            {
                if (player == 0) //move p1 balls   
                {   
                    g.setp1Balls(from, g.getp1Balls(from) - 1); 
                    g.setp1Balls(to, g.getp1Balls(to) + 1);
                    hasMoved = true;
                }
                if (player == 1) //move p2 balls   
                {   
                    g.setp2Balls(from, g.getp2Balls(from) - 1); 
                    g.setp2Balls(to, g.getp2Balls(to) + 1);
                    hasMoved = true;
                }
            }
        }
    }
}

void GameBoard::setupBoard()  //runs each round
{
    for (int loop = 0; loop < 5; loop++)
    {
        abacus[loop] = "OO----------OO";    //setup board
        p1Balls[loop] = 2; p2Balls[loop] = 2;   //setup balls
    }
}
GameBoard::GameBoard()  //runs at initialization
{
    setupBoard();
}
void GameBoard::print(std::string when, int player)
{   
    int midLength = 15;
    //setup current board
    for (int loop = 0; loop < 5; loop++)    //repeat for each rung
    {
        abacus[loop] = "";
        //p1 (left) side
        if (when == "stab" && player == 1)
        {    
            for (int p1 = 0; p1 < p1Balls[loop]-1; p1++)
                abacus[loop] += "O";
            abacus[loop] += "o";    //p2 stab indicator
        }   
        else 
        {
            for (int p1 = 0; p1 < p1Balls[loop]; p1++)
                abacus[loop] += "O";
        }

        //middle rungs
        midLength = 15 - (p1Balls[loop] + p2Balls[loop]);
        for (int middle = 0; middle < midLength; middle++)
            cout << "-";

        //p2 (right) side
        if (when == "stab" && player == 0)
        {
            abacus[loop] += "o";    //p1 stab indicator
            for (int p2 = 0; p2 < p2Balls[loop]-1; p2++)
                abacus[loop] += "O";
        }
        else
        {
            for (int p2 = 0; p2 < p2Balls[loop]; p2++)
                abacus[loop] += "O";
        }
    }

    //board print options, based on when function's called
    if (when == "idle") //cout just board
    {
        for (int loop = 0; loop < 5; loop++)
            cout << abacus[loop] << endl;
    }
    if (when == "move") //cout board with rung labels
    {
        for (int loop = 0; loop < 5; loop++)
            cout << abacus[loop] << " rung " << loop + 1 << endl;
    }
    if (when == "stab") //cout board with rung labels && empty icons
    {
        for (int loop = 0; loop < 5; loop++)    //rung labels
        {
            cout << abacus[loop] << " rung " << loop + 1;
            if (player == 0 && p2Balls[loop] == 0)   //empty icons, p1 Stab
                cout << " - empty!";
            else if (player == 1 && p1Balls[loop] == 0)   //empty icons, p2 Stab
                cout << " - empty!";
            cout << endl;
        }
    }
}
//getters/setters

bool PlayerTurn::getStabbed() {return hasStabbed;}
bool PlayerTurn::getMoved() {return hasMoved;}

int GameBoard::getp1Balls(int rung) {return p1Balls[rung];}
void GameBoard::setp1Balls(int rung, int value) {p1Balls[rung] = value;}

int GameBoard::getp2Balls(int rung) {return p2Balls[rung];}
void GameBoard::setp2Balls(int rung, int value) {p2Balls[rung] = value;}

int GameBoard::getScore(int player) {return scores[player];}
void GameBoard::addToScore(int player) {scores[player] += 1;}