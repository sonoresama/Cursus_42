/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:19:56 by eorer             #+#    #+#             */
/*   Updated: 2023/09/29 17:56:35 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONE_BOOK_H
# define PHONE_BOOK_H
# include "Contact.hpp"

class PhoneBook {
	public :
		PhoneBook();
		void add_contact();
		void search_contact();
		void print_contacts();
		void init_phonebook(std::string str);
		~PhoneBook();

	private :
		Contact contacts[8];
		int	size;
};

#endif
