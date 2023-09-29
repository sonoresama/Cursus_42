/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:26:50 by eorer             #+#    #+#             */
/*   Updated: 2023/09/29 18:38:57 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <list>

PhoneBook::PhoneBook(){
	this->size = 0;
}

PhoneBook::~PhoneBook(){
}

void	PhoneBook::add_contact(){
	if (this->size < 8)
	{
		this->contacts[this->size].init_contact(this->size);
		this->size++;
	}
	else
		this->contacts[7].init_contact(7);
}

int	is_all_digit(std::string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		char c = str[i];
		if (!isdigit(c))
			return (0);
	}
	return (1);
}

void	PhoneBook::search_contact(){
	std::string str;

	std::cout << std::endl;
	std::cout << "-------------- PHONE CONTACTS -------------" << std::endl;
	std::cout << "  INDEX   | FIRSTNAME| LASTNAME | NICKNAME " << std::endl;
	std::cout << "-------------------------------------------" << std::endl;
	this->print_contacts();
	do
	{
		std::cout << std::endl << "Enter the contact index : ";
		std::cin >> str;
		if (!is_all_digit(str) || stoi(str) < 0 || stoi(str) > this->size - 1)
			std::cout << "Sorry, wrong index";
	} while (stoi(str) < 0 || stoi(str) > this->size - 1);
	this->contacts[stoi(str)].print_contact_infos();
	return;
}

void	PhoneBook::print_contacts(){
	int	i = 0;
	while (i < 8)
	{
		this->contacts[i].print_contact_list();
		i++;
	}
}

void	PhoneBook::init_phonebook(std::string str){
	if (str.empty())
		return ;
	if (!str.compare("ADD"))
		this->add_contact();
	else if (!str.compare("SEARCH"))
		this->search_contact();
	else
		std::cout << "Sorry, I don't know this command." << std::endl;
}
