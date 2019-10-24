#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"

class Deck {
public:
    Deck(); //Constructor
    ~Deck(); //Destructor
    Deck(const Deck& origDeck); //Copy Constructor
    Deck& operator=(Deck rhs); //Copy Assignment Operator
    void PopDeck(); //Populate the Deck
    void ShufDeck(); //Shuffle the Deck
    Card RemCard(); //Remove a Card
    bool AddCard(Card c); //Add a Card
private:
    Card* cards;
    int arraySize;
    int cardsLeft;
};


#endif //BLINDMANSBLUFF_DECK_H
