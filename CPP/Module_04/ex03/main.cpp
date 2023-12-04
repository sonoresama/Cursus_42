/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 17:04:47 by eorer             #+#    #+#             */
/*   Updated: 2023/12/04 18:13:57 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "AMateria.hpp"

int	main(void)
{
	Ice ice;
	Ice frozen(ice);
	AMateria* blue = new Ice();

	std::cout << "ice type : " << ice._getType() << std::endl;
	std::cout << "frozen type : " << frozen._getType() << std::endl;
	std::cout << "blue type : " << blue->_getType() << std::endl;
	return (0);
}
