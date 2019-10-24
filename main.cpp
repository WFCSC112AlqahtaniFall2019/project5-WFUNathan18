#include <iostream>
#include <string>
#include <cctype>
#include "Card.h"
#include "Deck.h"
using namespace std;

int main() {
    cout << "Welcome to Blind Man's Bluff" << endl << endl;
    bool play, invalid, guessedHigher, anyCardsLeft;
    string response;
    int nWin = 0, nLoss = 0, nTie = 0;
    Deck cardDeck; //Deck of 52 Cards
    Card compCard, userCard;
    srand(time(NULL));

    cardDeck.PopDeck(); //Populate Deck
    cardDeck.ShufDeck(); //Shuffle Deck

    play = true;
    anyCardsLeft = true;
    while(play && anyCardsLeft) {
        // assign values to computer and user
        compCard = cardDeck.RemCard();
        userCard = cardDeck.RemCard();

        // get user's bet
        cout << "Computer's card is a " << compCard.PrintCardName() << endl;
        invalid = true;
        while(invalid) {
            cout << "Do you think your number is higher or lower? (H/L)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'H') {
                // continue playing
                guessedHigher = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'L') {
                // break out of while(play) loop
                guessedHigher = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }

        // determine outcome
        if((compCard < userCard && guessedHigher) || (compCard > userCard && !guessedHigher)) {
            cout << "Great! You're right:" << endl;
            nWin++;
        } else if((compCard > userCard && guessedHigher) || (compCard < userCard && !guessedHigher)) {
            cout << "Sorry, you're wrong:" << endl;
            nLoss++;
        } else {
            cout << "It's a tie:" << endl;
            nTie++;
        }
        cout << "\tyour value is " << userCard.PrintCardName() << endl;

        // ask user to play again
        invalid = true;
        while(invalid && anyCardsLeft) {
            cout << "Play again? (Y/N)" << endl;
            cin >> response;
            if (toupper(response.at(0)) == 'Y') {
                // continue playing
                play = true;
                invalid = false;
            } else if (toupper(response.at(0)) == 'N') {
                // break out of while(play) loop
                play = false;
                invalid = false;
            } else {
                // invalid response, ask again
                cout << "Invalid response..." << endl;
                invalid = true;
            }
        }
    }

    // output stats
    cout << "Thanks for playing!" << endl;
    cout << "Your record was " << nWin << "-" << nLoss << "-" << nTie << " (W-L-T)" << endl;

    return 0;
}