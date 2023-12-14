/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:49:53 by eorer             #+#    #+#             */
/*   Updated: 2023/12/14 14:14:17 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"

class AForm;

class	PresidentialPardonForm : public AForm
{
	public :
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &cpy);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &cpy);
		~PresidentialPardonForm();

		std::string	_getTarget() const;
		void	execute(const Bureaucrat& executor) const;

	private :
		PresidentialPardonForm();
		std::string _target;
};
