#include <iostream>

int main(void)
{
  std::pair<std::string, int> test = {"emile", 42};
  std::cout << test.first << std::endl;
  std::cout << test.second << std::endl;
  return (0);
}
//
//{1, 453 2 56 36 34345 55 43 }
//
//{453 56 343 55}         {55 56 343 453}  {43 55 56 342 453}
//{1 2 36 43}             {43 2 36 1}      {2 36 1}
//
//{453, 343}        {343 453}          {55 56 343 453}
//{56, 55}          {55 56}
//
//{343 453}
