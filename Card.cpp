#include "Card.h"

#include <string>
using namespace std;

Card::Card() {
    nRank = 0;
    nSuit = 0;
}

Card::Card(int initNumRank, int initNumSuit) {
    nRank = initNumRank;
    nSuit = initNumSuit;
}

bool Card::operator>(Card c) {
    if (this->nRank > c.nRank) {
        return true;
    }
    else if ((this->nRank == c.nRank) && (this->nSuit > c.nSuit)) {
        return true;
    }
    else {
        return false;
    }
}

string Card::PrintCardName() {
    return ranks[nRank] + " of " + suits[nSuit];
}
