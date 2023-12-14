/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:41:16 by eorer             #+#    #+#             */
/*   Updated: 2023/12/14 15:56:37 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AFrom;

class Intern{
	public :
		Intern();
		Intern(const Intern &cpy);
		Intern &operator=(const Intern &cpy);
		~Intern();

		AForm *formSCF(std::string tName);
		AForm *formRRF(std::string tName);
		AForm *formPPF(std::string tName);
		AForm *makeForm(std::string fName, std::string tName);
};
