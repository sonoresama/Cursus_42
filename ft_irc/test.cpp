#include <iostream>
#include <sstream>
#include <vector>

int main(void)
{
  std::stringstream ss("hello ca va ou quoi");
  std::string str = "Wsh tito c comment";
  std::vector<std::string> test;
  std::string tmp;

//  while (std::getline(ss, tmp, ' '))
//  {
//    test.push_back(tmp);
//  }
  ss.str(str);
  std::cout << str << std::endl;
  return (0);

}
