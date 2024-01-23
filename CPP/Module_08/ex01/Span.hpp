/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:34:00 by emileorer         #+#    #+#             */
/*   Updated: 2024/01/18 15:33:50 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class	Span
{
	public :
		Span(unsigned int N);
		Span(const Span &cpy);
		Span& operator=(const Span &cpy);
		~Span();

		void	addNumber(int n);
		void	addRange(int _range);
		int		shortestSpan();
		int		longestSpan();

		std::vector<int>::iterator _begin();
		std::vector<int>::iterator _end();

		class NumberException : public std::exception
		{
			const char* what() const throw();
		};
		class	SpanException : public std::exception
		{
			const char* what() const throw();
		};
		class	OORException : public std::exception
		{
			const char* what() const throw();
		};
	private :
		Span();
		std::vector<int>	_container;
		unsigned int	_max_size;
};
