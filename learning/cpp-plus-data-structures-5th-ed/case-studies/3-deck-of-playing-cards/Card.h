// Card Header File

#include <string>

using namespace std;

enum Suit {CLUB, DIAMOND, HEART, SPADE};
enum RelationType {LESS, EQUAL, GREATER};

class Card
{
    public:
        Card();
        Card(int initRank, Suit initSuit);
        int getRank() const;
        Suit getSuit() const;
        string toString() const;
        RelationType compareTo(const Card& otherCard) const;
    private:
        int rank;
        Suit suit;
};