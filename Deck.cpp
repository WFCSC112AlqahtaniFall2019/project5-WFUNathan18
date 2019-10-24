#include <iostream>
#include <ctime>
#include "Deck.h"
using namespace std;

Deck::Deck(int aSize) {
    if (aSize > 0) {
        cards = new Card[aSize];
        arraySize = aSize;
        cardsLeft = 52; //# of cards left
    }
    else {
        cards = 0;
        arraySize = 0;
    }
}

Deck::~Deck() {
    cout << "-Calling Destructor-" << endl;
    delete[] cards;
}

Deck::Deck(const Deck& origDeck) {
    cout << "-Calling Copy Constructor-" << endl;
    cards = new Card[arraySize];
    *cards = *(origDeck.cards);
    arraySize = origDeck.arraySize;
}

Deck& Deck::operator=(const Deck& rhs) {
    cout << "-Calling Assignment Operator-" << endl;
    Deck temp(rhs); //Copy Constructor
    swap(cards, temp.cards);
    return *this;
}

Deck& Deck::operator=(Deck rhs) {
    cout << "-Calling Assignment Operator" << endl;
    swap(cards, rhs.cards);
    return *this;
}

void Deck::PopDeck(Deck d) {
    cout << "-Populating Deck-" << endl;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 14; j++) {
            AddCard(i, j, d);
        }
    }
}

void Deck::ShufDeck(Deck d) {
    for (int i = 0; i < (d.cardsLeft ^ 2); i++) {
        srand(time(0));
        swap(d.cards[(rand() % d.cardsLeft)], d.cards[(rand() % d.cardsLeft)]);
    }
}

Card Deck::RemCard(Deck d) {
    if (d.cardsLeft == 0) { //If one card is left, do not subtract further
        return d.cards[d.cardsLeft];
    }
    else {
        d.cardsLeft--;
        return d.cards[d.cardsLeft];
    }
}

bool Deck::AddCard(int suit, int rank, Deck d) {
    if (d.cardsLeft < 0) { //If deck is full, subtract 1 extra to account for array logic
        if (d.cardsLeft == 52) {
            d.cardsLeft--;
            d.cards[d.cardsLeft] = Card(rank, suit);
            d.cardsLeft--;
            return true;
        }
        else {
            d.cards[d.cardsLeft] = Card(rank, suit);
            d.cardsLeft--;
            return true;
        }

    }
    else {
        return false;
    }
}