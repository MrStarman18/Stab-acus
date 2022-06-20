#include <iostream>
/*Developer: Justin T. Alexander
Date: May 24, 2022
Project: Host Text (Part of Stab-acus)
This program's functions should provide a random text sample based on time of game.*/
using namespace std;

int randomNumber(int low, int high)
{
    srand(time(NULL));
    int range = (high - low) + 1;
    return low + (rand() % range);
}

std::string introText()
{
    string firstLine[10]{};
    firstLine[0] = "Get ready for the one...the only...Stab-acus!\n";
    firstLine[1] = "Hello and welcome to Stab-acus!\n";
    firstLine[2] = "Come one come all, and experience Stab-acus!\n";
    firstLine[3] = "It's a beautiful day for some Stab-acus!\n";
    firstLine[4] = "Those boarding for a game of Stab-acus, you're in the right place!\n";
    firstLine[5] = "...\n(are we live?)\nHello and Stab-acus! Yeah! Stabby!\n";
    firstLine[6] = "Welcome to Stab-acus!\n";
    firstLine[7] = "Check your watches everybody, it's time for some Stab-acus!\n";
    firstLine[8] = "Stab-acus! Now that's what I'm talking about!\n";
    firstLine[9] = "Step right up folks, Stab-acus is about to begin!\n";
    int chosenOne = randomNumber(0,9);

    string secondLine[11]{};
    secondLine[0] = "My name's [REDACTED], and I look forward to hosting this match!\n";
    secondLine[1] = "My name's [REDACTED], and I'll be your host today!\n";
    secondLine[2] = "We've got everything set up here, so let's get started!\n";
    secondLine[3] = "Let's have some fun!\n";
    secondLine[4] = "The only game that makes an abacus fun!\n(wait, are we allowed to say that? okay cool.)\n";
    secondLine[5] = "Let's rock!\n";
    secondLine[6] = "Looks like another exciting game's in store for today!\n";
    secondLine[7] = "Please keep your arms, legs, and small children away from the abacus for the duration of this event.\n"; //Finish this one
    secondLine[8] = "Let's get ready to rumble!!!!!\n";
    secondLine[9] = "The latest two-player gaming sensation!\n";
    secondLine[10] = "Let's see a good, clean match!\nYou ready?\n";
    //and so on
    int chosenTwo = randomNumber(0,10);

    return firstLine[chosenOne] + secondLine[chosenTwo] +'\n';
}
std::string rulesText()
{
    string firstLine[6]{};
    firstLine[0] = "But first, let's read the rules.\n";
    firstLine[1] = "But first, let's hear some rules.\n";
    firstLine[2] = "Before we get started, let's read the rules.\n";
    firstLine[3] = "Let's start off with some rules.\n";
    firstLine[4] = "First things first, let's read the rules.\n";
    firstLine[5] = "Before we get started, let's hear some rules.\n";
    int chosenOne = randomNumber(0,5);

    string rules = "*Ahem.*\nStab-acus is a game for two players.\nEach of you will start with 10 balls on your side of the abacus, divided evenly across 5 rungs.\n";
    rules += "On your turn, you may use one of these balls to Stab or Move.\nAnd if you Stab first, then you can still Move after!\nBut what do those mean?\n"; 
    rules += "Stabbing is an offensive maneuver that destroys one of your opponent's balls on a chosen rung.\nMeanwhile, Moving peacefully moves one of your balls from one rung to another.\n";
    rules+= "If you Stab your opponent on an empty rung, then you win the round!\n";

    return firstLine[chosenOne] + rules + '\n';
}
std::string stabText()
{
    string firstLine[25]{};
    firstLine[0] = "That'll hurt!\n";
    firstLine[1] = "Right where it counts!\n";
    firstLine[2] = "Oh, I can't watch!!\n";
    firstLine[3] = "BOOM!!\n";
    firstLine[4] = "Say goodbye to that ball!\n";
    firstLine[5] = "Say goodnight, ball!\n";
    firstLine[6] = "Hasta la vista, baby!\n";
    firstLine[7] = "YEEOUCH!!\n";
    firstLine[8] = "Hope they didn't need that one!\n";
    firstLine[9] = "They'll feel that one!\n";
    firstLine[10] = "That was brutal!\n";
    firstLine[11] = "SHIA KAZING!!\n";
    firstLine[12] = "Adios!\n";
    firstLine[13] = "That's gotta sting!\n";
    firstLine[14] = "BANG!!\n";
    firstLine[15] = "POW!!\n";
    firstLine[16] = "I felt that one!\n";
    firstLine[17] = "That looked critical!\n";
    firstLine[18] = "Ouch!\n";
    firstLine[19] = "An explosive attack!\n";
    firstLine[20] = "Not for the faint of heart!\n";
    firstLine[21] = "A powerful advance!\n";
    firstLine[22] = "Rest in peace, ball!\n";
    firstLine[23] = "Oh great Heavens!\n";
    firstLine[24] = "YOWZA!!\n";
    //firstLine[25] = "Right in the Stabacussy!\n";
    int chosenOne = randomNumber(0,24);
    return firstLine[chosenOne];
}
std::string betweenRoundText(int winningPlayer, int losingPlayer, int roundNumber, int p1Score, int p2Score)
{
    string winner = to_string(winningPlayer + 1);   //+1 so that players are cout as 1 or 2, not 0 or 1
    string loser = to_string(losingPlayer + 1);
    string round = to_string(roundNumber);
    string nextRound = to_string(roundNumber + 1);
    string p1 = to_string(p1Score);
    string p2 = to_string(p2Score);

    string firstLine[15]{};
    firstLine[0] = "(what round is this? " + round + "?)\nThat's it for round " + round + "!\n";
    firstLine[1] = "So, come here often? I mean,, um,,,, uh,,,,,\n";
    firstLine[2] = "Having a good time yet? Nothing like some Stab-acus to bring us together!\n";
    firstLine[3] = "You just got stabbed!...-acus.\n";
    firstLine[4] = "That's it for round " + round + "!\n";
    firstLine[5] = "And now a word from our sponsors:\n\"No.\"\n";
    firstLine[6] = "With that, round " + round + " is over!\n";
    firstLine[7] = "That's a round winner for Player " + winner + "!\n";
    firstLine[8] = "And round " + round + " goes to Player " + winner + "!\n";
    firstLine[9] = "And this round goes to Player " + winner + "!\n";
    firstLine[10] = "Round " + round + " is over!\n";
    firstLine[11] = "Now that was entertainment! Nothing beats an exciting round of Stab-acus!\n";
    firstLine[12] = "Round " + round + ". Finished!!\n";
    firstLine[13] = "This round's over!\n";
    firstLine[14] = "Who's having fun? I bet you are, Player " + winner + "!\n";
    int chosenOne = randomNumber(0,14);

    string scoreLine[5]{};
    scoreLine[0] = "Current score is: " + p1 + " to " + p2 + ".\n";
    scoreLine[1] = "The score's: " + p1 + " and " + p2 + ".\n";
    scoreLine[2] = "Now, it's " + p1 + " to " + p2 + ".\n";
    scoreLine[3] = "The score's: " + p1 + " to " + p2 + ".\n";
    scoreLine[4] = "The score's at: " + p1 + " and " + p2 + ".\n";
    int chosenScore = randomNumber(0,4);
    //similar options as EndingText, but personalized for middle rounds.
    string secondLine[14]{};
    secondLine[0] = "And that score was brought to you by Stab-acus Studios! That's fun you can count on!\n";
    secondLine[1] = "Oh and don't be mad, Player " + loser + ". Turn it around in round " + nextRound + "!\n";
    secondLine[2] = "Stab-acus! Woo! Yeah!\n";
    secondLine[3] = "Let's go Player " + loser + "! I'm rooting for you this round!\n";
    secondLine[4] = "Let's go Player " + loser + "! I love a good underdog!\n";
    secondLine[5] = "Coming up: round " + nextRound + "! Let's get to it!\n";
    secondLine[6] = "Next up, another exciting round of stabbing and..abacuses? abaci? abacusi?\n";
    secondLine[7] = "Now it's time for round " + nextRound + "! Let's Stab! That! -Acus!\n";
    secondLine[8] = "Wanna hear a joke about an abacus?\nIt's the little things that count.\n";
    secondLine[9] = "Insert abacus pun here!\n...(who wrote this?)\n";
    secondLine[10] = "Will round " + nextRound + " be any different?\n";
    secondLine[11] = "Ooh I cant wait for round " + nextRound + "! Let's get to it!\n";
    secondLine[12] = "Round "+ nextRound + "starts off with you, Player " + loser + "!\n";
    secondLine[13] = "This next round starts with you, Player " + loser + "!\n";
    int chosenTwo = randomNumber(0,13);

    return '\n' + firstLine[chosenOne] + scoreLine[chosenScore] + secondLine[chosenTwo] +'\n';
}
std::string endingText(int winningPlayer, int losingPlayer, int p1Score, int p2Score)
{
    string winner = to_string(winningPlayer + 1);
    string loser = to_string(losingPlayer + 1);
    string p1 = to_string(p1Score);
    string p2 = to_string(p2Score);

    string firstLine[5]{};
    firstLine[0] = "And that's the game!\n";
    firstLine[1] = "That's game over!\n";
    firstLine[2] = "That's game!\n";
    firstLine[3] = "And that's it!\n";
    firstLine[4] = "Game over!\n";
    int chosenOne = randomNumber(0,4);

    string congrats = "Congratulations, Player " + winner + "!\n";

    string scoreLine[5]{};
    scoreLine[0] = "Final score is: " + p1 + " to " + p2 + ".\n";
    scoreLine[1] = "The final score's: " + p1 + " and " + p2 + ".\n";
    scoreLine[2] = "Ending score is: " + p1 + " to " + p2 + ".\n";
    scoreLine[3] = "The ending score's: " + p1 + " to " + p2 + ".\n";
    scoreLine[4] = "The score's: " + p1 + " and " + p2 + ".\n";
    int chosenScore = randomNumber(0,4);

    string secondLine[10]{};
    secondLine[0] = "Hope to see you again sometime for some more Stab-acus!\n";
    secondLine[1] = "Good game! See you next time!\n";
    secondLine[2] = "Good game! Take care!\n";
    secondLine[3] = "Good game!\n";
    secondLine[4] = "And " + loser + ", you can always come back here for a rematch!\nUntil then!\n";
    secondLine[5] = "Thank you for playing!\n";
    secondLine[6] = "Thanks for playing! Hope to see you again sometime!\n";
    secondLine[7] = "Good game! Well played!\n";
    secondLine[8] = "Good game! Thank you for playing!\n";
    secondLine[9] = "And " + loser + ", you can always come back here for a rematch!\nSee you then!\n";
    int chosenTwo = randomNumber(0,9);

    string credits = "\nGame developed by J Alex (@MrStarman18)\n";
    string special = "\nSpecial thanks:\nNoah J\n";
    //similar to IntroText. Maybe add some live options based on winner/loser?
    return firstLine[chosenOne] + congrats + scoreLine[chosenScore] + secondLine[chosenTwo] + credits + special + '\n';
}