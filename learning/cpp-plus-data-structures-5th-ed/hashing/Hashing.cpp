// learning/cpp-plus-data-structures-5th-ed/hashing/Hashing.cpp

/*
is it possible to design a search of O(1)?

in theory, it's not impossible.
let's look at an example:
a list of employees for a company. each of the employees
has an ID number in the range 0-99. we want to access
the employee records using the key idNum. if we store the
elements in an array that is indexed from 0 to 99, we can
directly access any employee's record through the array
index. there is a one-to-one correspondance between the element
keys and the array index.

if the size of the array goes huge, however, it's impractical
to set up that array.

what if we keep the array size down to the size that we
actually need (an array of 100 elements) and use just
the last two digits of the key to identify each employee?
for instance, the element of employee 53374 is in
employee.info[74] and employee 81235 is in employee.info[35].
the position of employee 81235 precedes that of employee 53374.
the elements are sorted with respect to some "function" of the
key value.

this function is called a "hash" function and the search
technique is "hashing". in the case of employees, the
hash function is (key % 100).

int ItemType::hash() const
{
    return (idNum & MAX_ITEMS);
}

this hash function has two uses. first, it is used as a method
of accessing the list element. the result of the hash function
tells us where to look for a particular element.

simplified version of the function retrieveItem:
void ListType<ItemType>::retrieveItem(ItemType& item)
{
    int location;

    location = item.hash();
    item = info[location];
}

second, the hash function determines where in the array to
store the element.
void ListType<ItemType>::insertITem(ItemType item)
{
    int location;

    location = item.hash();
    info[location] = item;
}
*/

/*
Collisions

id 01234 and id 91234 both hash to the same location, info[34].
a good hash function minimizes such collisions by spreading
the elements uniformly througout the array. it is extremely
difficult to avoid collisions.
*/

/*
Linear Probing

a simple approach to resolving collisions is to store the
colliding element in the next available space. this is
linear probing.

example, id 77003 is in info[3] id 50003 added and is in
info[4].

the following version if insertItem uses linear probing:

void ListType<ItemType>::insertItem(ItemType item)
{
    int location;
    location = item.hash();
    // empy item is some semantically illegal value (-1)
    while (info[location] != emptyItem)
        location = (location + 1) % MAX_ITEMS;
    info[location] = item;
}

to search for an element, we perform hash on the key,
then compare the desired key to the actual key, if
they don't match, use linear probing.

following is retrieveItem that uses this approach:

void ListType<ItemType>::retrieveItem(ItemType& item, bool& found)
{
    int location;
    int startLoc;
    bool moreToSearch = true;

    startLoc = item.hash();
    location = startLoc;

    do
    {
        if (info[location] == item || info[location] == emptyItem)
            moreToSearch = false;
        else
            location = (location + 1) % MAX_ITEMS;
    } while (location != startLocation && moreToSearch);

    found = (info[location] == item);

    if (found)
        item = info[location];
}

deletion algorithm
set location to item.hash()
set info[location] to emptyItem

deletion complicates matters. we need to create a constant value,
deletedItem, to process slots correctly. after many deletions,
the search path to a record may travel through many array slots.
this wandering may cause the efficiency of retrieving deteriorate.
*/

/*
Clustering

clustering is the tendency of elements to become unevenly distributed
in the hash table, with many elements clustering around a single
hash location.

a good hash function produces a uniform distribution of indexes
throughout the array's index range.
*/

/*
Rehashing

rehashing is resolving a collision by computing a new hash location
from a hash function that manipulates the original location rather
than the element's key.

the technique of linear probing discussed here is an example of
collision resolution by "rehashing". if the hash function produces
a collision, the hash value serves as the input to a "rehash
function".

we used the rehash function (hashValue + 1) % 100.

for rehashing with linear probing, we can use any function
(hashValue + constant) % arraySize. hashValue and constant must be
relatively prime.

in linear probing, we add a constant in each successive use of
the rehash function. a second approach, quadratic probing, makes
the result of rehashing dependent on how many times the function
has been applied. (hashValue + I^2) % arraySize

a third approach uses a pseudorandom number generator to determine
the increment to hashValue. random probing is good for eliminating
clustering but it tends to be slower than the other techniques.
*/

/*
Buckets and Chaining

bucket is a collection of elements associated with a particular
hash function. letting each computed hash location contain slots
for multiple elements. each of these multi-element locations is
called a bucket.

chain is a linked list of elements that share the same hash
function. using the hash values not as the actual location of
the element, but rather as the index into an array of pointers.
each pointer accesses a chain of elements that share the same
hash location.
*/