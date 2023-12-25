// learning/cpp-plus-data-structures-5th-ed/recursion/Recursion.cpp



// base case: the answer is explicitly known, no need for a recursive call
// general case: the answer is expressed in terms of a smaller version of itself
// recursive algorithm: the solution expressed in terms of a call to itself



// example: factorial
int factorial(int number)
{
    if (number == 0)
        return 1;
    else
        return number*factorial(number-1);
}



// verifying recursive functions
// three question method
/*
1. the base-case question: is there a nonrecursive way out of the function?

2. the smaller-caller question: does each recursive call to the function involve a 
smaller case of the original problem, leading inescapably to the base case?

3. the general-case question: assuming that the recursive calls work correctly,
does the entire function work correctly?
*/



// writing recursive functions
/*
1. get an exact definition of the problem

2. determine the size of the problem

3. identify and solve the base cases

4. identify and solve the general cases
*/

// example: a boolean function
struct ListType
{
    int length;
    int info[];
};

// find a value in the list
// recursive solution: return (value is in the first position) ? (value is in the rest of the list)

bool valueInList(ListType list, int value, int startIndex)
{
    if (list.info[startIndex] == value)
        return true;
    else if (startIndex == (list.length - 1))
        return false;
    else
        return valueInList(list, value, startIndex + 1);
}



// using recursion to simplify solutions
int combination(int group, int members)
{
    if (members == 1)
        return group;
    else if (members == group)
        return 1;
    else
        return (combination(group-1, members-1) + combination(group-1, members));
}



// recursive linked list processing
struct NodeType;
class ListType
{
    public:
        // members
    private:
        NodeType* listData;
};

// print the list in reverse order
// recursive solution: print out the second section of the list, then print out the first element
#include <iostream>
void reversePrint(NodeType* listPtr)
{
    if (listPtr != nullptr)
    {
        reversePrint(listPtr->next);
        std::cout << listPtr->info << std::endl;
    }
}



// a recursive version of binary search
template<class ItemType>
bool binarySearch(ItemType info[], ItemType item, int fromLocation, int toLocation)
{
    if (fromLocation > toLocation)
        return false;
    else
    {
        int midPoint;
        midPoint = (fromLocation + toLocation) / 2;
        if (item < info[midPoint])
            return binarySearch(info, item, fromLocation, toLocation-1);
        else if (item == info[midPoint])
            return true;
        else return binarySearch(info, item, fromLocation+1, toLocation);
    }
}



// recursive versions of putItem and deleteItem
// insertItem
template<class ItemType>
void insertItem(NodeType<ItemType>*& listPtr, ItemType item)
{
    if (listPtr == nullptr || item < listPtr->info)
    {
        NodeType<ItemType>* tempPtr = listPtr;
        listPtr = new NodeType<ItemType>;
        listPtr->info = item;
        listPtr->next = tempPtr;
    }
    else
        insert(listPtr->next, item);
}

// deleteItem
template<class ItemType>
void deleteItem(NodeType<ItemType>*& listPtr, ItemType item)
{
    if (item == listPtr->info)
    {
        NodeType<ItemType>* tempPtr = listPtr;
        listPtr = listPtr->next;
        delete tempPtr;
    }
    else
        delete(list->next, item);
}