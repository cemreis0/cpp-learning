// learning/cpp-plus-data-structures-5th-ed/set/SetImplicitRepresentation.h

template<class ItemType>
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