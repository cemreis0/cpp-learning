// learning/cpp-plus-data-structures-5th-ed/set/Set.h

// #include "Map.h"
// file Map.h must include a definition of ItemType and a function named
// "map" that maps an item of ItemType into an index between 0 and max -1
// if the parameterized constructor is used and between 0 and 399 if
// the default constructor is used

class SetType
{
    public:
        SetType();
        SetType(int max);
        ~SetType();
        SetType(const SetType otherSet);
        void makeEmpty();
        void store(ItemType item);
        void delete(ItemType item);
        bool isEmpty();
        bool isFull();
        int cardinalityIs();
        SetType unionOf(SetType setB);
        SetType intersection(SetType setB);
        SetType difference(SetType setB);
    private:
        int maxItems;
        ItemType* items;
};