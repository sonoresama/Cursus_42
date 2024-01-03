/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:34:00 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/19 15:13:59 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>

class	Span
{
	public :
		Span(unsigned int N);
		Span(const Span &cpy);
		Span& operator=(const Span &cpy);
		~Span();

		void	addNumber(int n);
		int		shortestSpan();
		int		longestSpan();
		class NumberException : public std::exception
		{
			const char* what() const throw();
		};
		class	SpanException : public std::exception
		{
			const char* what() const throw();
		};
	private :
		Span();
		std::vector<int>	_container;
		unsigned int	_max_size;
};
