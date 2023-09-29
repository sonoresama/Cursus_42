/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:47:43 by eorer             #+#    #+#             */
/*   Updated: 2023/09/29 18:15:07 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>

void	print_spaces(int number)
{
	for (int i = 0; i < number; i++)
		std::cout << " ";
}

void	print_string(std::string str, bool pipe)
{
	print_spaces((str.length() > 10) ? 0 : 10 - str.length());
	if (str.length() == 10)
	{
		std::cout << str;
		return;
	}
	std::cout << str.substr(0, (str.length() < 10) ? str.length() : 9);
	if (str.length() > 10)
		std::cout << ".";
	if (pipe)
		std::cout << "|";

}

Contact::Contact(){
}

Contact::~Contact(){
}

void Contact::init_contact(int index){
	std::cout << "Enter firstname : ";
	std::cin >> this->firstname;
	std::cout << "Enter lastname : ";
	std::cin >> this->lastname;
	std::cout << "Enter nickname : ";
	std::cin >> this->nickname;
	std::cout << "Enter number : ";
	std::cin >> this->number;
	std::cout << "Enter secret : ";
	std::cin >> this->dark_secret;
	this->index = index;
}

void Contact::print_contact_infos(){
	std::cout << "INFOS" << std::endl;
}

void Contact::print_contact_list(){
	int	len;
	std::string spaces;

	if (this->firstname.empty() || this->lastname.empty() || this->nickname.empty())
		return ;
	std::cout << "         " << this->index << "|";
	print_string(this->firstname, true);
	print_string(this->lastname, true);
	print_string(this->nickname, false);
	std::cout << std::endl;
}
