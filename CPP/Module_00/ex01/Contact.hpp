/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 18:46:01 by eorer             #+#    #+#             */
/*   Updated: 2023/09/26 18:55:35 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class	Contact{
	public :
		std::string prenom;
		std::string nom;
		std::string num;
		Contact(std::string prenom, std::string nom, std::string num);
		~Contact();
};

#endif
