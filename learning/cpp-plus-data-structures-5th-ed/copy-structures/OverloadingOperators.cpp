// learning/cpp-plus-data-structures-5th-ed/copy-structures/OverloadingOperators.cpp

// myStack = yourStack would result in two pointers pointing to the same stack
// rather than two distinct stacks

// we can overcome this by overloading the meaning of the assignment operator

template<class ItemType>
class StackType
{
    void operator=(StackType<ItemType>);
};

// the function definition looks like this
template<class ItemType>
void StackType<ItemType>::operator=(StackType<ItemType> anotherStack)
{

}