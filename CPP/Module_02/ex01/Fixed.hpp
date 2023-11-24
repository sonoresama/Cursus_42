/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:21 by eorer             #+#    #+#             */
/*   Updated: 2023/11/24 16:43:44 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# define COUT(x) std::cout << x << std::endl

# include <iostream>
# include <string>
# include <cmath>

class	Fixed{
  public:
		Fixed();
		Fixed(const int i_raw);
		Fixed(const float f_raw);
		Fixed(const Fixed &n);
		Fixed &operator=(const Fixed &n);
		~Fixed();
	
		int	getRawBits(void) const;
		void setRawBits(int	const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	
  private:
		int	_number;
		static const int	_fract = 8;
};

std::ostream& operator<<(std::ostream &out, Fixed const &rhs);

#endif
