#include <iostream>
#include <map>
#include <unordered_map>

int	main(void)
{
	{
		std::string	coucou = "COUCOU";
		int	n = 42;
		std::map<std::string, int>	m;
	
		m[coucou] = n;
		m.insert(std::pair<std::string, int>("Test", 52));
		m.insert(std::pair<std::string, int>("Kaa", 51));
		m.insert(std::pair<std::string, int>("Bbb", 53));
		m.insert(std::pair<std::string, int>("Zzz", 55));
		for (std::map<std::string, int>::iterator it = m.begin(); it != m.end(); ++it)
			std::cout << it->first << " " << it->second << std::endl;
	}
	std::cout << std::endl;
	{
		std::string	coucou = "COUCOU";
		int	n = 42;
		std::unordered_map<std::string, int>	m;
	
		m[coucou] = n;
		m.insert(std::pair<std::string, int>("Test", 52));
		m.insert(std::pair<std::string, int>("Kaa", 51));
		m.insert(std::pair<std::string, int>("Bbb", 53));
		m.insert(std::pair<std::string, int>("Zzz", 55));
		for (std::unordered_map<std::string, int>::iterator it = m.begin(); it != m.end(); ++it)
			std::cout << it->first << " " << it->second << std::endl;
	}

	return (0);
}
