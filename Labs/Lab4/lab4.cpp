/*
Title: Lab4.cpp
Author: Cobain Irwin
Date: 20260921
Purpose: Create a game and be able to get user input to play the game.
Idea: We are going to make it to where the player plays a
guess-the-card game.
*/

#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <string>
#include <ctype.h>


using namespace std;

int main()
{
    // Setting up rand func
    srand(time(0));

    // While loop things
    int times_played(0);
    int difference_of_rank(0);
    int difference_of_suit(0);

    //strings
    string replay_game_question(" ");

    // User input
    int user_card_rank_guess(0);
    int user_card_suit_guess(0);

    // Bools
    bool playing_game(true);
    bool rank_found(false);
    bool suit_found(false);

    // Card random values
    string card_suit_name(" ");
    int card_rank = rand() % 13 + 1;
    string card_rank_name(" ");
    int card_suit = rand() % 4 + 1;


    // Determine card suit
    switch (card_suit)
    {
        case 1:
            card_suit_name = "Clubs";
            break;

        case 2:
            card_suit_name = "Hearts";
            break;

        case 3:
            card_suit_name = "Spades";
            break;

        case 4:
            card_suit_name = "Diamonds";
            break;
    }

    // Determine card rank name
    if ((card_rank > 1) && (card_rank < 11))
    {
        card_rank_name = to_string(card_rank) + " of ";
    }
    else
    {
        switch (card_rank)
        {
            case 1:
                card_rank_name = "Ace of ";
                break;

            case 11:
                card_rank_name = "Jack of ";
                break;

            case 12:
                card_rank_name = "Queen of ";
                break;

            case 13:
                card_rank_name = "King of ";
                break;
        }
    }


    cout << "\n========================================\n";
    cout << "        CARD GUESSING GAME\n";
    cout << "========================================\n";

    cout << "\nHow to enter your guesses:";
    
    while (playing_game == true && times_played < 3)
    {
        

        cout << endl;
        //cout << card_rank_name << card_suit_name << endl; for testing what comes out

        //explain how to play
        
        cout << "---------- RANKS ----------\n";
        cout << "Ace   : 1     | 2-10  : 2-10\n";
        cout << "Jack  : 11    | Queen : 12\n";
        cout << "King  : 13\n";
        
        cout << "---------- SUITS ----------\n";
        cout << "Clubs    : 1  | Hearts   : 2\n";
        cout << "Spades   : 3  | Diamonds : 4\n";
        cout << "Black Suits   | Red Suits\n";
        
        cout << "============================\n";

        cout << "Guess #" << times_played + 1 << " of 3\n";
        cout << "----------------------------\n";
        
        cout << "Now, please provide to me the guess of the rank!\n";
        // Get player's guesses
        cout << "Response: ";
        cin >> user_card_rank_guess;
        

        cout << "Now, please provide to me the guess of the suit!\n";
        cout << "Card Suit guess: ";
        cin >> user_card_suit_guess;

        // Check rank guess
        if (user_card_rank_guess == card_rank)
        {
            cout << "You guessed the correct rank!\n";
            rank_found = true;
        }
        else
        {
            difference_of_rank = abs(card_rank - user_card_rank_guess);

            if (difference_of_rank == 1)
            {
                cout << "Extremely close! You were only 1 rank away.\n";
                
            }
            else if (difference_of_rank <= 3)
            {
                cout << "Pretty close! You were " << difference_of_rank
                    << " ranks away.\n";
            }
            else
            {
                cout << "Not very close. You were more than 3 ranks away.\n";
            }
        }

        // Check suit guess
        if (user_card_suit_guess == card_suit)
        {
            cout << "You guessed the suit correctly!\n";
            suit_found = true;
        }
        else
        {
            if ((user_card_suit_guess == 1 || user_card_suit_guess == 3) &&
                (card_suit == 1 || card_suit == 3))
            {
                cout << "Wrong suit, but you guessed the correct color: Black!\n";
            }
            else if ((user_card_suit_guess == 2 || user_card_suit_guess == 4) &&
                     (card_suit == 2 || card_suit == 4))
            {
                cout << "Wrong suit, but you guessed the correct color: Red!\n";
            }
            else
            {
                cout << "Wrong suit and wrong color. Try again!\n";
            }
        }
        
        // Count this attempt
        times_played++;
        
        // Check if game is finished
        if ((rank_found == true && suit_found == true) || times_played == 3)
        {
            if (rank_found == true && suit_found == true)
            {
                cout << "\nYou found the card!\n";
            }
            else
            {
                cout << "\nYou ran out of guesses!\n";
            }
        
            cout << "The card was: "
                 << card_rank_name << card_suit_name << endl;
        
            cout << "\nDo you want to play again? (y/n)\n";
            cout << "Response: ";
            cin >> replay_game_question;
        
            for (int i = 0; i < replay_game_question.length(); i++)
            {
                replay_game_question[i] = tolower(replay_game_question[i]);
            }
        
            if (replay_game_question == "y" || replay_game_question == "yes")
            {
                cout << "\nEnjoy your next round!\n";

                //resetting game state here.
        
                times_played = 0;
                rank_found = false;
                suit_found = false;
        
                card_rank = rand() % 13 + 1;
                card_suit = rand() % 4 + 1;
        
                // You'll need to update card_rank_name and
                // card_suit_name here for the newly generated card.
            }
            else if (replay_game_question == "n" ||
                     replay_game_question == "no")
            {
                cout << "\nI appreciate you testing my program!"
                     << " Have a wonderful day!\n";
        
                playing_game = false;
            }
        }

        
    }

    return 0;
}