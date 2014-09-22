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
    int addWord(std::string str);
    std::string getString() const;

private:
    std::string m_sentence;
};

#endif // MYHEADER_H
