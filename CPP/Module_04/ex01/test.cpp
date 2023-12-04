#include <iostream>

std::string get_str(int i, std::string lists[10])
{
	return (lists[i]);
}

int	main(void)
{
	std::string lists[10];

	std::cout << get_str(-20, lists) << std::endl;
	lists[0] = "Hello";
	std::cout << get_str(0, lists) << std::endl;
	return (0);
}
