#include <iostream>
#include <ctime>
#include "Deck.h"
using namespace std;

Deck::Deck() {
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
    //*cards = *(origDeck.cards);
    for (int i = 0; i < origDeck.arraySize; i++) {
        cards[i] = origDeck.cards[i];
    }
    arraySize = origDeck.arraySize;
}

/*Deck& Deck::operator=(const Deck& rhs) {
    cout << "-Calling Assignment Operator-" << endl;
    Deck temp(rhs); //Copy Constructor
    swap(cards, temp.cards);
    return *this;
}*/

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
    srand(time(0));
    for (int i = 0; i < (cardsLeft ^ 2); i++) {

        swap(cards[(rand() % 52)], cards[(rand() % 52)]);
    }
}

Card Deck::RemCard() {

        cardsLeft--;
        return cards[cardsLeft];

}

bool Deck::AddCard(Card c) {
    if (cardsLeft < arraySize) { //If deck is full, subtract 1 extra to account for array logic
        cards[++cardsLeft]=c;
            return true;
        }
        else
            return false;

}