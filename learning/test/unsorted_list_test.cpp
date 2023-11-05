// test/unsorted_list_test.cpp

#include "../include/unsorted_list.h"
#include "../include/item.h"
#include <iostream>
using namespace std;

int main()
{
    UnsortedList unsortedList;

    Item item1;
    Item item2;
    Item item3;
    item1.initialize(12);
    item2.initialize(16);
    item3.initialize(20);

    unsortedList.putItem(item1);
    unsortedList.putItem(item2);
    unsortedList.putItem(item3);

    unsortedList.deleteItem(item3);

    cout << "length: " << unsortedList.getLength() << endl;
    cout << "is full: " << unsortedList.isFull() << endl;

    return 0;
}