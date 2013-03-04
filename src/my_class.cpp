#include "../include/my_class.h"

/** Create MyClass object
 */
MyClass::MyClass() : _myInt(0)
{

}

/** Destroy MyClass object
 */
MyClass::~MyClass()
{

}

/** A very simple function
 * @param delta add delta to _myInt
 * @return Value of _myInt
 */
int MyClass::myFunction(int delta)
{
    _myInt += delta;
    return _myInt;
}

