/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:21 by eorer             #+#    #+#             */
/*   Updated: 2023/11/24 13:15:27 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class	Fixed{
  public:
	Fixed();
	Fixed(const Fixed &n);
	Fixed &operator=(const Fixed &n);
	~Fixed();

	int	getRawBits(void) const;
	void setRawBits(int	const raw);

  private:
	  int	_raw;
	  static const int	_fract = 8;
};

#endif
