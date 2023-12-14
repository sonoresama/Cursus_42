/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:21:56 by eorer             #+#    #+#             */
/*   Updated: 2023/12/14 14:15:06 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <ctime>

class AForm;

class	RobotomyRequestForm : public AForm
{
	public :
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &cpy);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &cpy);
		~RobotomyRequestForm();

		std::string	_getTarget() const;
		void	execute(const Bureaucrat& executor) const;

	private :
		RobotomyRequestForm();
		std::string _target;
};
