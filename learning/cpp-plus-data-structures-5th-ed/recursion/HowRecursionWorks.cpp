// learning/cpp-plus-data-structures-5th-ed/recursion/HowRecursionWorks.cpp

/*
how recursion works

association of a memory address with a variable name is called "binding".
the point this occurs in compile/execute cycle is called "binding time".

static storage allocation associates variable names with memory locations
at compile time. dynamic storage allocation associates variable names with
memory locations at execute time.

when are the parameters of a function bound to a particular address in memory?
the answer tells us something about whether a language supports recursion.
*/

/*
static storage allocation

as a program is translated, the compiler creates a symbol table. when a
variable is declared, it enters symbol table and a memory location is
assigned to it.

int girlCount, boyCount, totalCount;

symbol table:
symbol      address
girlCount   0000
boycount    0001
totalCount  0002

where are the parameters of a function stored?
consider a function called countKids with two parameters and a local variable.
the compiler leaves room for the two formal parameters and the local variable
at addresses countkids - 1, countkids - 2, countkids - 3.

static storage allocation does not allow recursion. each call to a function
must be independent. intermediate values in recursion calls cannot be stored.
*/

/*
dynamic storage allocation

each invocation of a function needs its own work space. with dynamic
allocation, variable names are not bound to actual addresses until run time.
the compiler references variables by their relative addresses, not actual ones.

activation record (stack frame) is a record used at run time to store info
about a function call, including the parameters, local variables, register values,
and return address.

each call to a recursive function generates a new activation record. within the
function, references to the parameters and local variables use the values in
the activation record. the compiler adds "prologue" and "epilogue" to a function
to handle activation records.

"runtime stack" is a data structure that keeps track of activation records during
the execution of a program. when a function is invoked, its activation record
is pushed onto the runtime stack. each nested level of function calls adds another
activation record. after a function completes is execution, its activation record
is popped.

dynamic storage allocation allows recursion.
*/

/*
removing recursion

in cases where a recursive solution is not desired, two general techniques are
often substituted: iteration and stacking.

iteration:
    when the recursive call is the last action executed in a recursive function,
    the function terminates without using its values. we need to change the
    "smaller-caller" variables on the recursive call's parameter list and then
    jump back to the beginning of the function. we need a loop.

    in cases where the recursive call is the last statemente executed are called
    tail recursion. to remove recursion, tail recursion is usually replaced by
    iteration. many compiler do this automatically.

stacking:
    when the recursive call is not the last action executed in a recursive
    function, we cannot simply substitute a loop. we must replace the stacking
    performed by the system by the system with stacking performed by the
    programmer. we make use of other appropriate data structures.
*/

/*
deciding whether to use recursion

recursion is more costly in terms of computer time and space. a recursive
solution usually requires more overhead. recursion might be inherently
inefficient because of calculating the same values over and over.

when to use:
the depth of recursive calls is relatively shallow
the recursion roughly does the same amount of work as the nonrecursive version
the recursive version is shorther and simpler than the nonrecursive solution
*/