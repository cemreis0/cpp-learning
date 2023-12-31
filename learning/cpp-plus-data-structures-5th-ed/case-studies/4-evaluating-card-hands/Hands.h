// Hands Header File

#include "3-deck-of-playing-cards/Deck.h"
#include "sorted-list/SortedType.h"

class Hands
{
    public:
        Hands();
        Hands(int players);
        ~Hands();
        void deal(int numCards);
        SortedType getHand(int which);
    private:
        int numPlayers;
        SortedType* hands;
        Deck deck;
}