/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:46:01 by eorer             #+#    #+#             */
/*   Updated: 2023/09/28 17:13:23 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include "main.hpp"
# include "PhoneBook.hpp"

class	Contact{
	public :
		Contact();
		~Contact();
		void init_contact();
		void print_infos();

	private :
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string number;
		std::string dark_secret;
};

#endif
