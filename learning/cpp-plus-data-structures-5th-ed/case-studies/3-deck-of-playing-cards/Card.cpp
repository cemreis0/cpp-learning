// learning/cpp-plus-data-structures-5th-ed/case-studies/3-deck-of-playing-cards/Card.cpp

#include "Card.h"

Card::Card()
{
    rank = 1;
    suit = CLUB;
}

Card::Card(int initRank, Suit initSuit)
{
    rank = initRank;
    suit = initSuit;
}

int Card::getRank() const
{
    return rank;
}

Suit Card::getSuit() const
{
    return suit;
}

RelationType Card::compareTo(const Card& otherCard) const
// return relative position of self to otherCard
{
    if (suit < otherCard.suit)
        return LESS;
    else if (suit > otherCard.suit)
        return GREATER;
    else if (rank == otherCard.rank)
        return EQUAL;
    else if (rank == 1)
        return GREATER;
    else if (otherCard.rank == 1)
        return LESS;
    else if (rank < otherCard.rank)
        return LESS;
    else if (rank > otherCard.rank)
        return GREATER;
    else
        return EQUAL;
}

string Card::toString() const
{
    string convertRank[13] = 
    {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", 
    "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    string convertSuit[4] = {"Clubs", "Diamonds", "Hearts", "Spades"};

    string returnString = convertRank[rank-1] + " of " + convertSuit[suit];
    return returnString;
}