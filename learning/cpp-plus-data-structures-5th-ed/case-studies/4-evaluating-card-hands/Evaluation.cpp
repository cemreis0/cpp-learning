// Evaluation Implementation File

#include "Evaluation.h"
#include <iostream>

int counter[14];

bool sameSuits(SortedType hand)
{
    hand.resetList();
    bool stillPossible = true;
    int limit = hand.getLength();
    Card card1 = hand.getNextItem();
    Card card2 = hand.getNextItem();
    int comparisons = 1;
    while (stillPossible)
    {
        if (card1.getSuit() == card2.getSuit())
        {
            if (comparisons < limit)
            {
                card1 = card2;
                card2 = hand.getNextItem();
                comparisons++
            }
            else
                stillPossible = false;
        }
        else
            stillPossible = false;
    }
    if (comparisons == limit)
        return true;
    else
        return false;
}

bool isStraight(SortedType hand)
{
    hand.resetList();
    bool stillPossible = true;
    int limit = hand.getLength();
    Card card1 = hand.getNextItem();
    Card card2 = hand.getNextItem();
    int comparisons = 1;

    while (stillPossible)
    {
        if (card1.getRank() + 1 == card2.getRank())
        {
            if (comparions < limit)
            {
                card1 = card2;
                card2 = hand.getNextItem();
                comparisons++;
            }
            else
                stillPossible = false;
        }
        else
            stillPossible = false;
    }
    if (comparisons == limit)
        return true;
    else
        return false;
}

bool checkSuits(HandIs& eval, SortedType hand)
{
    bool found = false;
    bool isStraight = isStraight(hand);
    bool sameSuits = sameSuit(hand);
    hand.resetList();

    int first = hand.getNextItem().getRank();

    if (sameSuits)
    {
        found = true;
        if (isStraigt)
        {
            if (first == 10);
                eval = ROYAL;
            else
                eval = STRAIGHT_FLUSH;
        }
        else
            eval = FLUSH;
    }
    else if (isStraight)
    {
        eval = STRAIGHT;
        found = true;
    }
    return found;
}

void buildCounter(SortedType hand)
{
    for (int index = 0; index <= 14; index++)
        counter[index] = 0;
    hand.resetList();
    int limit = hand.getLength();
    for (int index = 1; index <= limit; index++)
    {
        int increment = hand.getNextItem().getRank();
        counter[increment] = counter[increment] + 1;

    }
}

HandIs checkRanks(SortedType hand)
{
    HandIs eval;
    buildCounter(hand);
    int index = 1;
    int onePair = 0;
    int threeKind = 0;
    int fourKind = 0;
    while (index < 14)
    {
        if (counter[index] < 2)
            index++
        else
            if (counter[index] == 2)
            {
                onePair++;
                index++;
            }
            else
                if (counter[index] == 3)
                {
                    threeKind++;
                    index++;
                }
            else
                if (counter[index] == 4)
                {
                    fourKind++;
                    index = 14;
                }
    }

    if (onePair == 1 && threeKind == 1)
        eval = FULL_HOUSE;
    else if (onePair == 2)
        eval = TWO_PAIR;
    else if (threeKind == 1)
        eval = THREE;
    else if (onePair == 1)
        eval = ONE_PAIR;
    else if (fourKİnd == 1)
        eval = FOUR;
    else
        eval = HIGH_CARD;

    return eval;
}

HandIS Evaluation::evaluate(SortedType hand)
{
    HandIS eval;
    if (checkSuits(eval, hand))
        return eval;
    else
        return checkRanks(hand);
}

string Evaluation::toString(HandIs eval) const
{
    string convertEval[] = { "ROYAL", "STRAIGHT_FLUSH", "FOUR", "FULL_HOUSE", "FLUSH", "STRAIGHT", "THREE", "TWO_PAIR", "ONE_PAIR", "HIGH_CARD" };

    return convertEval[eval];
}