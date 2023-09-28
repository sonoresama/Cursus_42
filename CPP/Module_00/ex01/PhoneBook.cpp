/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:26:50 by eorer             #+#    #+#             */
/*   Updated: 2023/09/28 17:51:39 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "main.hpp"

PhoneBook::PhoneBook(){
	this->size = 0;
}

PhoneBook::~PhoneBook(){
}

void	PhoneBook::add_contact(){
	if (this->size < 8)
		this->list[this->size++].init_contact();
	else
		this->list[7].init_contact();
}

void	PhoneBook::search_contact(){
	return;
}

void	PhoneBook::print_contct(int number){
	if (number > 7)
		return ;
	else
		this->list[number].print_infos();
}

void	PhoneBook::init_phonebook(std::string str){
	if (str.empty())
		return ;
	if (!str.compare("ADD"))
		this->add_contact();
	else if (!str.compare("SEARCH"))
		this->search_contact();
	else
	{
		system("Colour 0C");
		std::cout << "Sorry, I don't know this command." << std::endl;
	}
}

