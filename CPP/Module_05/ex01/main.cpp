/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:12:53 by eorer             #+#    #+#             */
/*   Updated: 2023/12/12 16:01:03 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#define COUT(x) std::cout << x << std::endl;

int	main(void)
{
	try
	{
		Form	a;
		Form	b("test", 100, 100);
		COUT(b);
		Form	c(b);
		COUT(c);COUT("");
//		Form	d("test2", 0, 0);

		Bureaucrat	tito("TITO", 100);
		COUT(tito);
		tito.signForm(c);
		COUT(c);
		tito.signForm(c); COUT("");

		Bureaucrat	titi("TITI", 101);
		COUT(titi);
		titi.signForm(b);
		COUT(b); COUT("");
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << DEFAULT << std::endl;
	}
	return (0);
}
