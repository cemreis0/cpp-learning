// Evaluation Header File

#include <string>
#include "sorted-list/SortedType"

enum HandIs {ROYAL, STRAIGH_FLUSH, FOUR, FULL_HOUSE, FLUSH, STRAIGHT, THREE, TWO_PAIR, ONE_PAIR, HIGH_CARD};

using namespace std;

class Evaluation
{
    public:
        HandIs evaluate(SortedType hand);
        string toString(HandIs eval) const;
}