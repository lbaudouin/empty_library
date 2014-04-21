#include <iostream>
#include "my_class.h"

/**
* @author Léo Baudouin\n
* @em baudouin.leo@gmail.com
*/

int main(int argc, char* argv[])
{
  MyClass myClass;
  myClass.addString("Hello");
  myClass.addString("world");
  myClass.addString("!!!");
  
  std::cout << myClass.getString() << std::endl;
  return 0;
}

