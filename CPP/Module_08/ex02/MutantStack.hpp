/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:45:21 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/22 15:40:31 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
//		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::deque<T>::iterator iterator;

		MutantStack() : std::stack<T>()
		{
			std::cout << "MutantStack constructor called" << std::endl;
		}

		MutantStack(const MutantStack& cpy) 
		{
			std::cout << "MutantStack copy constructor called" << std::endl;
			*this = cpy;
		}

		MutantStack &operator=(const MutantStack& cpy)
		{
			this->c = cpy.c;
		}
		
		~MutantStack()
		{
			std::cout << "MutantStack destructor called" << std::endl;
		}

		iterator	begin(void)
		{
			return (this->c.begin());
		}

		iterator	end(void)
		{
			return (this->c.end());
		}
};

