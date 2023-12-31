// Hands Implementation File

#include "Hands.h"
#include <iostream>

using namespace std;

Hands::Hands()
{
    SortedType();
}

Hands::Hands(int numPlayers)
{
    numPlayers = players;
    hands = new SortedType[numPlayers];
    deck.generateDeck();
}

Hands::~Hands()
{
    delete [] hands;
}

void Hands::deal(int numCards)
{
    deck.resetList();

    for (int i = 0; i < 7; i++)
        deck.shuffle();

    Card card
    deck.resetList();

    for (int i = 0; i < numPlayers; i++)
        hands[i].makeEmpty();
    
    for (int cards = 0; cards < numCards; cards++)
        for (int players  0; players < numPlayers; players++)
        {
            card = deck.getNextItem()
            hands[players].putItem(card);
        }
}

SortedType Hands::getHand(int which)
{
    return hands[which - 1];
}