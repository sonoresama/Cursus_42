/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:21 by eorer             #+#    #+#             */
/*   Updated: 2023/12/07 16:17:23 by eorer            ###   ########.fr       */
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
		~Fixed();
	
		//overloads
		Fixed &operator=(const Fixed &n);
		bool operator>(const Fixed &n);
		bool operator<(const Fixed &n);
		bool operator>=(const Fixed &n);
		bool operator<=(const Fixed &n);
		bool operator==(const Fixed &n);
		bool operator!=(const Fixed &n);
		Fixed operator+(const Fixed &n);
		Fixed operator-(const Fixed &n);
		Fixed operator*(const Fixed &n);
		Fixed operator/(const Fixed &n);
		Fixed &operator++(); //prefix
		Fixed &operator--(); //prefix
		Fixed operator++(int);	//suffix
		Fixed operator--(int);	//suffix

		//static
		static Fixed& min(Fixed &a, Fixed &b);
		const static Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		const static Fixed& max(const Fixed &a, const Fixed &b);

		//others
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
