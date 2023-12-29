// Deck & Card Demo File

#include <iostream>
#include "Deck.h"
#include "Card.h"

int main()
{
    using namespace std;

    void printDeck(Deck deck);

    Deck deck;
    Card card;

    cout << "Deck after default constructor" << endl;
    printDeck(deck);

    deck.generateDeck();
    cout << "Deck after generateDeck()" << endl;
    printDeck(deck);

    for (int counter = 0; counter < 10; counter++)
        deck.shuffle();
    cout << "Deck after 10 shuffles" << endl;
    printDeck(deck);

    return 0;
}

void printDeck(Deck deck)
{
    using namespace std;

    if (deck.getLength() == 0)
        cout << "Deck is empty" << endl;

    else
    {
        deck.resetList();
        Card card;

        for (int counter = 1; counter <= deck.getLength(); counter++)
        {
            card = deck.getNextItem();
            cout << card.toString() << endl;
        }
    }
}