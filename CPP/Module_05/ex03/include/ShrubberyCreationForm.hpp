/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:26:55 by eorer             #+#    #+#             */
/*   Updated: 2023/12/14 14:14:07 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class AForm;

class	ShrubberyCreationForm : public AForm
{
	public :
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &cpy);
		~ShrubberyCreationForm();

		std::string	_getTarget() const;
		void	execute(const Bureaucrat& executor) const;

	private :
		ShrubberyCreationForm();
		std::string _target;
};
