#include <iostream>
#include <ctime>
#include "Deck.h"
using namespace std;

Deck::Deck() {
    cout << "-Calling Constructor" << endl;
    arraySize=52;
    cardsLeft=0;
    cards= new Card[52];
}

Deck::~Deck() {
    cout << "-Calling Destructor-" << endl;
    delete[] cards;
}

Deck::Deck(const Deck& origDeck) {
    cout << "-Calling Copy Constructor-" << endl;
    cards = new Card[arraySize];
    for (int i = 0; i < origDeck.arraySize; i++) {
        cards[i] = origDeck.cards[i];
    }
    arraySize = origDeck.arraySize;
}

Deck& Deck::operator=(Deck rhs) {
    cout << "-Calling Assignment Operator" << endl;
    swap(cards, rhs.cards);
    return *this;
}

void Deck::PopDeck() {
    cout << "-Populating Deck-" << endl;
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
            Card c(j, i);
            AddCard(c);
        }
    }
}

void Deck::ShufDeck() {
    cout << "-Shuffling Deck-" << endl;
    srand(time(0));
    for (int i = 0; i < (cardsLeft ^ 2); i++) {
        swap(cards[(rand() % 52)], cards[(rand() % 52)]);
    }
}

Card Deck::RemCard() { //Changes the place in the array where the cards will be given (begins at the right, moves toward the left)
        cardsLeft--;
        return cards[cardsLeft];
}

bool Deck::AddCard(Card c) {
    if (cardsLeft < arraySize) { //If the deck is not yet filled
        cards[++cardsLeft]=c;
            return true;
        }
        else
            return false;

}