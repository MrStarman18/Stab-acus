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
    cout << "Enter how many rounds you'd like to play.\nFor example, enter \"2\" to end the game when a player reaches 2 wins (best of 3).\n";
    cin >> winCondition;
    int roundNumber = 1, roundWinner = 0, currentPlayer = 2;
    bool gameOver = false, roundOver = false, turnOver = false;
    GameBoard game;
    
    while (gameOver != true)    //game running
    {   
        game.setupBoard();   //run creator to reset board?
        roundOver = false;
        string action;
        if (roundNumber = 1)    //input for first player
        {
            while (currentPlayer > 1)   //if invalid input, keep asking
            {
                string player;
                cout << "Enter which player will be starting first.\n\"1\" or \"2\", or \"flip a coin\" to let me decide.\n";
                cin >> player;
                if (player == "1" || player == "one" || player == "One" || player == "ONE")
                {    
                    currentPlayer = 0;
                    break;
                }
                else if (player == "2" || player == "two" || player == "Two" || player == "TWO")
                {    
                    currentPlayer = 1;
                    break;
                }
                else if (player == "flip a coin" || player == "flipacoin" || player == "flip coin" || player == "coin" || player == "flip" || player == "f" || player == "flipa coin" || player == "flip acoin")
                {
                    currentPlayer = randomNumber(0,1);
                    break;
                }    
                cout << "I didn't get that. Let's try it again.\n";
            }
        }
        cin >> player 1, player 2, or "flip a coin"
        if (roundNumber >= 2)   //player who just lost gets to start
            currentPlayer = !roundWinner;
        while (roundOver != true)
        {
            game.print("idle");

            PlayerTurn thisTurn;    //Player Turn only tracks values for each turn, not whole game
            while (turnOver != true)    //not allowed to skip turn using invalid inputs
            {
                cout << "Player " << to_string(currentPlayer + 1) << ", what would you like to do?" << endl
                << "\"stab\" or \"move\": ";
                cin >> action;
                if (action == "stab" || action == "Stab" || action == "stab!" || action == "Stab!" || action == "s")
                {
                    thisTurn.stab(game, currentPlayer, &roundOver, &roundWinner);
                    turnOver = true;    //still allowed to move after; this is unaffected by turnOver
                }
                else if (action == "move" || action == "Move" || action == "move!" || action == "Move!" || action == "m")
                {    
                    thisTurn.move(game, currentPlayer);
                    turnOver = true;
                }

                if (thisTurn.getMoved() == false && thisTurn.getStabbed() == true)
                {
                    cout << "Player " << currentPlayer + 1 << ", you're still allowed to move. Would you like to?" << endl
                    << "\"yes\" or \"no\": ";
                    cin >> action;
                    if (action == "yes" || action == "y" || action == "sure" || action == "yeah" || action == "ok" || action == "okay" ||action == "move" || action == "Move" || action == "move!" || action == "Move!" || action == "m")
                        thisTurn.move(game, currentPlayer);
                }
                currentPlayer = !currentPlayer;
            }

        }
        game.addToScore(roundWinner);    //roundWinner (& roundOver) should be updated accordingly after empty stab
        cout << betweenRoundText(roundWinner, !roundWinner, roundNumber, game.getScore(0), game.getScore(1));
        cout << "Enter any button to proceed: ";
        cin >> proceed;
        ++roundNumber;
        //check for game over (one player has reached input winCondition)
        if (game.getScore(0) == winCondition)
        {
            cout << endingText(0, 1, game.getScore(0), game.getScore(1));
            gameOver = true;
        }
        else if (game.getScore(1) == winCondition)
        {
            cout << endingText(1, 0, game.getScore(0), game.getScore(1));
            gameOver = true;
        }
    }
return 0; 
}