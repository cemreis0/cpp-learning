// cpp-plus-data-structures-5th-ed/stack/Balanced.cpp

/*
StackType implementation

Problem:            determine whether a set of parantheses is well formed

Specific problem:   given a set of different types of paired symbols, determine whether the opening and
                    closing versions of each type are paired correctly
*/

#include "StackType.h"
#include <iostream>
bool isOpen(char symbol);
bool isClosed(char symbol);
bool matches(char symbol, char openSymbol);

int main()
{
    using namespace std;
    char symbol, openSymbol;
    StackType stack;
    bool balanced = true;

    cout << "Enter an expression and press return" << endl;
    cin.get(symbol);

    while (symbol != '\n' && balanced)
    {
        if (isOpen(symbol))
            stack.push(symbol);
        else if (isClosed(symbol))
        {
            if (stack.isEmpty())
                balanced = false;
            else
            {
                openSymbol = stack.getTop();
                stack.pop();
                balanced = matches(symbol, openSymbol);
            }
        }
        cin.get(symbol);
    }

    if (!stack.isEmpty())
        balanced = false;
    if (balanced)
        cout << "Expression is well formed." << endl;
    else
        cout << "Expression is ill-formed." << endl;

    return 0;
}

bool isOpen(char symbol)
{
    if (
        symbol == '(' ||
        symbol == '[' ||
        symbol == '{'
    )
        return true;
    else
        return false;
}

bool isClosed(char symbol)
{
    if (
        symbol == ')' ||
        symbol == ']' ||
        symbol == '}'
    )
        return true;
    else
        return false;
}

bool matches(char symbol, char openSymbol)
{
    return (
        (openSymbol == '(' && symbol == ')') ||
        (openSymbol == '[' && symbol == ']') ||
        (openSymbol == '{' && symbol == '}')
    );
}