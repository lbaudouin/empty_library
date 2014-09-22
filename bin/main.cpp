#include <iostream>
#include "my_class.h"

/**
* @author Léo Baudouin\n
* @em baudouin.leo@gmail.com
*/

int main(int argc, char* argv[])
{
  MyClass myClass;
  myClass.addWord("Hello");
  myClass.addWord("world");
  myClass.addWord("!!!");
  
  std::cout << myClass.getString() << std::endl;
  return 0;
}

