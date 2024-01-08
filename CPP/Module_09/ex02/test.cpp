#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <utility>

int	main(void)
{
    std::list<int>  l = {3, 56, 25, 5, 2, 63};
    std::list<std::pair<int, int>>  s;

    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it)
        s.push_back(std::make_pair(*it, *(++it)));

    for (std::list<std::pair<int, int>>::iterator its = s.begin(); its != s.end(); ++its)
    {
        std::cout << its->first << " ";
        std::cout << its->second << std::endl;
    }
    return (0);
}
