/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:43:53 by eorer             #+#    #+#             */
/*   Updated: 2023/11/17 16:47:07 by emileorer        ###   ########.fr       */
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
	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);
};

#endif
