#include "Executive.h"


  int main(int argc, char* argv[])
{
  if(argc>1)
  {
    std::string fileName = argv[1];
    Executive ex1(fileName);
  }
}
