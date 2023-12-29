// Deck Header File

// base class of Deck: UnsortedType

#include "unsorted-list/UnsortedType.h"
#include "Card.h"

class Deck : public UnsortedType<Card>
{
    public:
        Deck(); // set deck to empty
        void generateDeck(); // generate deck in bridge (poker) order
        void shuffle(); // reorder the cardsS
};