/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:17:42 by eorer             #+#    #+#             */
/*   Updated: 2023/10/04 18:46:43 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

# define COUT(str) std::cout << str << std::endl
# define CERR(str) std::cerr << str << std::endl

class Fixed {
  public :
	Fixed(); 						//Constructeur par defaut
	Fixed(const int integer);		//Surcharge du constructeur avec un int en parametre
	Fixed(const float floater);		//Surcharge du constructeur avec un float en parametre
	Fixed(const Fixed &copy);		//Constructeur de copie
	Fixed &operator=(const Fixed &rhs);
	~Fixed();

	int	getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;

  private:
	int	_fixedPointNumber;
	const int _fixedPointPos = 8;
};

std::ostream& operator<<(std::ostream &out, Fixed const &rhs);

#endif
