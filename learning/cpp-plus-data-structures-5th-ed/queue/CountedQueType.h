// cpp-plus-data-structures-5th-ed/queue/CountedQueType.h

#pragma once

#include "QueType.h"

// Inheritance
/*
CountedQueType is derived from QueType.

CountedQueType: derived class
QueType:        base class
public QueType: public base class, all public members of QueType are also
                public members of CountedQueType

Every object of type CountedQueType has an object of type QueType as a subobject.
An object of type CountedQueType is an object of type QueType
*/

class CountedQueType : public QueType
{
    public:
        CountedQueType(int max);
        void enqueue(int item); // overridden function
        void dequeue(int& item); // overridden function
        int getLength() const;
    private:
        int length;
};