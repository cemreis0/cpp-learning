// Deck Implementation File

#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

Deck::Deck()
// set deck to empty
{

}

void Deck::generateDeck()
// generate deck in bridge (poker) order
{
    makeEmpty();
    for (Suit suit = CLUB; suit <= SPADE; suit = Suit(suit+1))
        for (int value = 1; value <= 13; value++)
            putItem(Card(value, suit));
}

Deck merge(Deck shorterDeck, Deck longerDeck);
void Deck::shuffle()
// splits deck into two parts, using random number generator
// to determine the size of parts. parts are merged one card
// at a time, using helper function merge.
{
    srand(time(NULL));
    Deck deckA, deckB;
    Card card;
    int splitSize;

    splitSize = (rand() % 8 + 1) + 22;

    resetList();

    for (int counter = 1; counter <= splitSize; counter++)
    {
        card = getNextItem();
        deckA.putItem(card);
    }

    for (int counter = splitSize+1; counter <= getLength(); counter++)
    {
        card = getNextItem();
        deckB.putItem(card);
    }

    makeEmpty();

    if (splitSize < (52-splitSize))
        *this = merge(deckA, deckB);
    else
        *this = merge(deckB, deckA);
}



// -----------------------------------------------------------------



Deck merge(Deck shorterDeck, Deck longerDeck)
{
    Deck deck;
    Card card;
    int counter;
    shorterDeck.resetList();
    longerDeck.resetList();

    for (counter = 1; counter <= shorterDeck.getLength(); counter++)
    {
        card = shorterDeck.getNextItem();
        deck.putItem(card);
        card = longerDeck.getNextItem();
        deck.putItem(card);
    }

    int remaining = longerDeck.getLength() - shorterDeck.getLength();
    for (counter = 1; counter <= remaining; counter++)
    {
        card = longerDeck.getNextItem();
        deck.putItem(card);
    }

    return deck;
}