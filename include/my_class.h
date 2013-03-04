#ifndef MYHEADER_H
#define MYHEADER_H

#include <vector>
#include <iostream>

/** @class MyClass
* @short Define functions and variables for MyClass
*/
class MyClass
{
public:
    MyClass();
    ~MyClass();
    int myFunction(int delta = 1);

private:
    int _myInt;
};

#endif // MYHEADER_H
