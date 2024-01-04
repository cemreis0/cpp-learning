// learning/cpp-plus-data-structures-5th-ed/searching/Searching.cpp

/*
Linear Search

suppose we want to insert elements as quickly as possible.
we would put the element into the last slot in an array-based
list and the first slot in a linked list. these are O(1)
insertion algorithms. the resulting list is sorted according
to the time of insertion, not according to a key value.

to search this list we must use a linear (sequential) search.

------------------------------------------------------------
linearSearch(unsorted data)
initialize location to position of first item
set found to false
set moreToSearch to (have not examined info(last))
while (moreToSearch AND NOT found)
    if item equals info(location)
        set found to true
    else
        set location to next(location)
        set moreToSearch (have not examined info(last))
if NOT found
    set location to NULL
------------------------------------------------------------

this search is O(N). average case is N/2.
*/

/*
High-Probability Ordering

sometimes certain list elements are in much greater demand
than others. to improve searching, put the
most-often-desired elements at the beginning of the list.

if the elements in the list are not static or if you cannot
predict their relative demand, move each element accessed
to the front of the list. a second approach suggests
swapping the element that is found with the element
that predeces it.

keeping the active elements in front of the list does not
affect the worst case. it improves the average performance.

lists in which the relative positions of the elements are
changed in an attempt to imrpove search efficiency are
called self-organizing or self-adjusting lists.
*/

/*
Key Ordering

if the list is sorted according to the key value, we no
longer need to search the whole list to discover that
an element does not exist. rather, we need to search only
until it has passed the element's logical place in the list.
*/

/*
Binary Searching

if the data elements are sorted and stored sequentially
ina na rray, we can improve the searching efficiency from O(N)
to O(log2N), using binary search. the binary search algorithm
improves the search efficiency by limiting the search to the
are where the element might be. divide-and-conquer-approach.

the binary search is no guaranteed to be faster for searching
very small lists; however, as the number of elements increases
the disparity between linear search and binary search grows
ver quickly.
*/