/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 15:17:42 by eorer             #+#    #+#             */
/*   Updated: 2023/10/04 16:45:34 by eorer            ###   ########.fr       */
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
	Fixed();
	Fixed(const Fixed &f);
	Fixed &operator=(const Fixed &f);
	~Fixed();

	int	getRawBits(void) const;
	void setRawBits(int const raw);

  private:
	int	_raw;
	const int _nb_bits = 8;
};

#endif
