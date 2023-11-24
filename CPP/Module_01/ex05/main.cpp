/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:50:38 by eorer             #+#    #+#             */
/*   Updated: 2023/11/17 17:20:59 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl harl;

	void	(Harl::*ft)(std::string);

	ft = &Harl::complain;
	(harl.*ft)("DEBUG");
	(harl.*ft)("INFO");   
	(harl.*ft)("WARNING");
	(harl.*ft)("ERROR");
//	harl.complain("DEBUG");
//	harl.complain("INFO");
//	harl.complain("WARNING");
//	harl.complain("ERROR");
	return (0);
}
