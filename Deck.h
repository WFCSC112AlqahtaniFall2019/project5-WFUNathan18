#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"

class Deck {
public:
    Deck(int aSize); //Constructor
    ~Deck(); //Destructor
    Deck(const Deck& origDeck); //Copy Constructor
    Deck& operator=(const Deck& rhs); //Copy Assignment Operator
    Deck& operator=(Deck rhs); //Copy Assignment Operator
    void PopDeck(Deck d); //Populate the Deck
    void ShufDeck(Deck d); //Shuffle the Deck
    Card RemCard(Deck d); //Remove a Card
    bool AddCard(int suit, int rank, Deck d); //Add a Card
private:
    Card* cards;
    int arraySize;
    int cardsLeft;
};


#endif //BLINDMANSBLUFF_DECK_H
