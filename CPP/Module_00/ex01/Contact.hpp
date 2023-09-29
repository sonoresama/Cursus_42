/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:46:01 by eorer             #+#    #+#             */
/*   Updated: 2023/09/29 17:56:40 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class	Contact{
	public :
		Contact();
		~Contact();
		void init_contact(int index);
		void print_contact_list();
		void print_contact_infos();

	private :
		int	index;
		std::string firstname;
		std::string lastname;
		std::string nickname;
		std::string number;
		std::string dark_secret;
};

#endif
