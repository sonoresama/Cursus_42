/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:45:50 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/19 17:16:10 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <list>
#include <vector>
#include <deque>
#include <algorithm>

int	main(void)
{
	std::list<int> lst;
	std::list<int>::iterator it;

	try
	{
		for (int i = 0; i < 10; i++)
			lst.push_back(i);
		it = easyfind(lst, 4);
		std::cout << *it << std::endl;
		it = easyfind(lst, 2);
		std::cout << *it << std::endl;
		it = easyfind(lst, 12);
		std::cout << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::vector<int> v;
	std::vector<int>::iterator v_it;

	try
	{
		for (int i = 0; i < 100; i+=11)
			v.push_back(i);
		v_it = easyfind(v, 11);
		std::cout << *v_it << std::endl;
		v_it = easyfind(v, 22);
		std::cout << *v_it << std::endl;
		v_it = easyfind(v, 12);
		std::cout << *v_it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::deque<int> d;
	std::deque<int>::iterator d_it;

	try
	{
		for (int i = 0; i < 100; i+=11)
			d.push_back(i);
		d_it = easyfind(d, 11);
		std::cout << *d_it << std::endl;
		d_it = easyfind(d, 22);
		std::cout << *d_it << std::endl;
		d_it = easyfind(d, 12);
		std::cout << *d_it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
