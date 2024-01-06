/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 17:28:14 by eorer             #+#    #+#             */
/*   Updated: 2024/01/06 23:16:54 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class	RPN
{
	public:
		RPN();
		RPN(const RPN& cpy);
		RPN& operator=(const RPN& cpy);
		~RPN();

		class FormatError : public std::exception
		{
			const char*	what() const throw();
		};

		std::stack<int>	_getStack();
		int	_getResult(std::string operation);
		int	_getResult();

	private:
		std::stack<int>	_stack;
		int	_result;
		void	_parseArg(std::string arg);
};

#endif
