#ifndef BLINDMANSBLUFF_DECK_H
#define BLINDMANSBLUFF_DECK_H

#include "Card.h"

class Deck {
public:
    Deck();
    ~Deck(); //Destructor
    Deck(const Deck& origDeck); //Copy Constructor
    Deck& operator=(const Deck& objToCopy); //Copy Assignment Operator
    void PopDeck();
    void ShufDeck();
    Card RemCard();
    bool AddCard();
private:
    Card* cards;
    int arraySize;
    int cardsLeft;
};


#endif //BLINDMANSBLUFF_DECK_H
