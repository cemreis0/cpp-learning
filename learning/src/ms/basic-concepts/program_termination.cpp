// src/ms/basic-concepts.cpp

int main()
{
    /*
    In C++, you can exit a program in these ways:

    Call the exit function.
    Call the abort function.
    Execute a return statement from main.
    */

    // Exit function
    /*
    The exit function, declared in <stdlib.h>, terminates a C++ program. 
    The value supplied as an argument to exit is returned to the operating system as the program's return code or exit code.
    By convention, zero means success.
    You can use the constants EXIT_FAILURE and EXIT_SUCCESS.
    */

    // Abort function
    /*
    The abort function also terminates a C++ program.
    The difference between exit and abort is that exit allows the C++ runtime termination processing to 
    take place (global object destructors get called). 
    abort terminates the program immediately. The abort function bypasses the normal 
    destruction process for initialized global static objects.
    */

    // atexit function
    // Use the atexit function to specify actions that execute before the program terminates.

    // return statement in main
    /*
    A return statement in main first acts like any other return statement.
        Any automatic variables are destroyed. Then, main invokes exit with the return value as a parameter.
    */

    return 0;
}