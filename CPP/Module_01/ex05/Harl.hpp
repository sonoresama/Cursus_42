/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:43:53 by eorer             #+#    #+#             */
/*   Updated: 2023/10/04 12:52:16 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>
# define COUT(str) std::cout << str << std::endl
# define CERR(str) std::cerr << str << std::endl

class Harl {
  public :
	Harl();
	~Harl();
	void complain(std::string level);
  
  private :
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);
};

#endif
