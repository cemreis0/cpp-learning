// learning/cpp-plus-data-structures-5th-ed/copy-structures/CopyConstructor.cpp

// first alternative: write a member function to perform the deep copy
// and explicity invoke it

// the copy constructor has a special syntax
// no return type, just the class name

template <class ItemType>
class StackType
{
    public:
        // copy constructor
        StackType(const StackType<ItemType>& anotherStack);
};

template <class ItemType>
StackType<ItemType>::StackType(const StackType<ItemType>& anotherStack)
{
    NodeType<ItemType> ptr1;
    NodeType<ItemType> ptr2;

    if (anotherStack.topPtr == nullptr)
        topPtr = nullptr;
    else
    {
        topPtr = new NodeType<ItemType>;
        topPtr->info = anotherStack.topPtr->info;
        ptr1 = anotherStack.topPtr->next;
        ptr2 = topPtr;

        while (ptr1 != nullptr)
        {
            ptr2->next = new NodeType<ItemType>;
            ptr2 = ptr2->next;
            ptr2->info = ptr1->info;
            ptr1 = ptr1->next;
        }
        ptr2->next = nullptr;
    }
}

// oneStack.copy(anotherStack); creates a copy of anotherStack and stores it in oneStack



// copy(myStack, yourStack) implementation
// syntactic device called a "friend function" is not a member of the class
// yet it has permission to access private class member directly

template<class ItemType>
class StackType
{
    public:
        friend void copy(StackType<ItemType>, StackType<ItemType>&);
};

template<class ItemType>
void copy(StackType<ItemType> original, StackType<ItemType>& copy)
{
    if (original.topPtr = nullptr)
        copy.topPtr = nullptr;
    else
    {
        NodeType<ItemType>* ptr1;
        NodeType<ItemType>* ptr2;

        copy.topPtr = new NodeType<ItemType>;
        copy.topPtr->info = original.topPtr->info;
        ptr1 = original.topPtr->next;
        ptr2 = copy.topPtr;
        
        while (ptr1 != nullptr)
        {
            ptr2->next = new NodeType<ItemType>;
            ptr2 = ptr2->next;
            ptr2->info = ptr1->info;
            ptr1 = ptr1->next;
        }
        ptr2->next = nullptr;
    }
}