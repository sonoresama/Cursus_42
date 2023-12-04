/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:46:26 by eorer             #+#    #+#             */
/*   Updated: 2023/11/17 16:48:24 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{}

Harl::~Harl()
{}

void	Harl::_debug(void)
{
	COUT("[DEBUG]");
	COUT("I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !");
}

void	Harl::_info(void)
{
	COUT("[INFO]");
	COUT("I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !");
}

void	Harl::_warning(void)
{
	COUT("[WARNING]");
	COUT("I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.");
}

void	Harl::_error(void)
{
	COUT("[ERROR]");
	COUT("This is unacceptable ! I want to speak to the manager now.");
}

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*f_ptrs[4])();

	f_ptrs[0] = &Harl::_debug;
	f_ptrs[1] = &Harl::_info;
	f_ptrs[2] = &Harl::_warning;
	f_ptrs[3] = &Harl::_error;
	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*f_ptrs[i])();
			return ;
		}
	}
}
