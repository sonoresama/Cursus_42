/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:19:56 by eorer             #+#    #+#             */
/*   Updated: 2023/09/28 17:30:59 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H
# include "main.hpp"
# include "Contact.hpp"

class PhoneBook {
	public :
		PhoneBook();
		void add_contact();
		void search_contact();
		void print_contact(int number);
		void init_phonebook(std::string str);
		~PhoneBook();

	private :
		Contact list[8];
		int	size;
};

#endif
