#include <iostream>
#include "stabacus-game.h"
using namespace std;

void PlayerTurn::stab(GameBoard g, int player, bool roundOver)
{
    if (hasStabbed = false)
    {
        
    }


    //if stab valid
        //if (balls-1) >= 0, balls = (balls-1)
        else    //balls == 0 when stabbed, ending round
        {
            roundOver = true;
            g.game
            roundWinner = player;   //used to influence hosttext
        }
}
void PlayerTurn::move(GameBoard g, int player)
{   //can't move after stabbing
    int from, to;
    if (hasMoved == false)
    {
        while (hasMoved == false)
        {
            g.print("move");
            cout << "Move one ball from rung __ to rung __:\nFrom rung: ";
            cin << from;
            cout << "to rung: ";
            cin << to;
            
            if (player == 0 && g.getp1Balls(from - 1) == 0)
                cout << "No ball in rung " << from << "to move!\n";
            else if (player == 1 && g.getp2Balls(from - 1) == 0)
                cout << "No ball in rung " << from << "to move!\n";
            else if (/*no open space on to rung*/)
                cout << "No room on rung " << to << "for another ball!\n";
            else 
            {
                if (player = 0) //move p1 balls   
                {   
                    g.setp1Balls(from, g.getp1Balls(from) - 1); 
                    g.setp1Balls(to, g.getp1Balls(to) + 1);
                    hasMoved = true;
                }
                if (player = 1) //move p2 balls   
                {   
                    g.setp2Balls(from, g.getp2Balls(from) - 1); 
                    g.setp2Balls(to, g.getp2Balls(to) + 1);
                    hasMoved = true;
                }
            }
        }
    }
}

GameBoard::GameBoard()  //runs each round, not just at initialization
{
    for (int loop = 0; loop < 5; loop++)
    {
        abacus[loop] = "OO----------OO";    //setup board
        p1Balls[loop] = 2; p2Balls[loop] = 2;   //setup balls
    }
}
void GameBoard::print(string when, int player )
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
        int midLength = 15 - (p1Balls[loop] + p2Balls[loop])
        for (int middle = 0; middle < midLength; middle++)
            cout << "-";

        //p2 (right) side
        if (when == "stab" && player == 0)
        {
            abacus[loop] += "o";    //p2 stab indicator
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
            if (player = 0 && p2Balls[loop] == 0)   //empty icons, p1 Stab
                cout << " - empty!";
            else if (player = 1 && p1Balls[loop] == 0)   //empty icons, p2 Stab
                cout << " - empty!";
            cout << endl;
        }
    }
}