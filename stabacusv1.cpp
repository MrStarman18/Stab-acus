#include <iostream>
#include "hosttext.h"   //___Text() functions, personality
#include "stabacus-game.h"
/*Developer: Justin T. Alexander
Date: May 21, 2022
This program is used to run a game of Stabacus*/
using namespace std;

int main()
{   
    std::string proceed;
    cout << introText();
    cout << "Enter any button to proceed: ";
    cin >> proceed;
    cout << rulesText();
    cout << "Enter any button to proceed: ";
    cin >> proceed;
    int winCondition;
    cout << "Enter how many rounds you'd like to play.\nFor example, enter \"2\" to play first player to 2 wins (best of 3).\n";
    cin >> winCondition;
    int roundNumber = 1, roundWinner = 0;
    bool gameOver = false, roundOver = false, turnOver = false;
    GameBoard game;
    
    while (gameOver != true)    //game running
    {   
        game.GameBoard();   //run creator to reset board?
        roundOver = false;
        string action;
        //if round 1, cin >> player 1, player 2, or "flip a coin"
        //if round 2+, currentPlayer = player who just lost
        while (roundOver != true)
        {
            game.print("idle");
            PlayerTurn thisTurn;    //Player Turn only tracks values for each turn, not whole game
            while (turnOver != true)    //not allowed to skip turn using invalid inputs
            {
                cout << "Player " << currentPlayer + 1 << ", what would you like to do?" << endl
                << "\"stab\" or \"move\": ";
                cin >> action;
                if (action == "stab" || action == "Stab" || action == "stab!" || action == "Stab!" || action == "s")
                {
                    thisTurn.stab(&game, currentPlayer, &roundOver);
                    turnOver = true;    //still allowed to move after; this is unaffected by turnOver
                }
                else if (action == "move" || action == "Move" || action == "move!" || action == "Move!" || action == "m")
                {    
                    thisTurn.move(&game, currentPlayer);
                    turnOver = true;
                }

                if (thisTurn.getMoved() == false && thisTurn.getStabbed() == true)
                {
                    cout << "Player " << currentPlayer + 1 << ", you're still allowed to move. Would you like to?" << endl
                    << "\"yes\" or \"no\": ";
                    cin >> action;
                    if (action == "yes" || action == "y" || action == "sure" || action == "yeah" || action == "move" || action == "Move" || action == "move!" || action == "Move!" || action == "m")
                        thisTurn.move(&game, currentPlayer);
                }
                currentPlayer = !currentPlayer;
            }

        }

        cout << betweenRoundText(roundWinner, !roundWinner, roundNumber, game.getScore(0), game.getScore(1));
        cout << "Enter any button to proceed: ";
        cin >> proceed;
        ++roundNumber;
        //check for game over (one player has reached input winCondition)
        if (game.getScore(0) == winCondition)
        {
            cout << endingText(0, 1, game.getScore(0), game.getScore(1))
            gameOver = true;
        }
        else if (game.getScore(1) == winCondition)
        {
            cout << endingText(1, 0, game.getScore(0), game.getScore(1))
            gameOver = true;
        }
    }
   
}