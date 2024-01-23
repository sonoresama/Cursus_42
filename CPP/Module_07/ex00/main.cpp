/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:35:29 by eorer             #+#    #+#             */
/*   Updated: 2024/01/16 13:18:15 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tmp.hpp"

int main( void )
{
  {
	float	a = 21.445f;
	float	b = 42.445f;

	std::cout << "The max of a: " << a << " and b: " << b << " is:" <<
	"\t" << max(a, b) << std::endl;

	std::cout << "The min of a: " << a << " and b: " << b << " is:" <<
	"\t" << min(a, b) << std::endl;

	std::cout << std::endl;

	std::cout << "before:\n\ta: " << a << "\n\tb: " << b << std::endl;
	swap(a, b);
	std::cout << "after:\n\ta: " << a << "\n\tb: " << b << std::endl;
	}

	std::cout << std::endl << "------------------------------------------------------------------" << std::endl << std::endl;

	{
	std::string	a = "String A";
	std::string b = "String B";

	std::cout << "The max of a: " << a << " and b: " << b << " is:" <<
	"\t" << ::max(a, b) << std::endl;

	std::cout << "The min of a: " << a << " and b: " << b << " is:" <<
	"\t" << ::min(a, b) << std::endl;

	std::cout << std::endl;

	std::cout << "before:\n\ta: " << a << "\n\tb: " << b << std::endl;
	::swap(a, b);
	std::cout << "after:\n\ta: " << a << "\n\tb: " << b << std::endl;
	}
    {
      std::cout << "Max 10 et 15 : " << max(10, 15) << std::endl;
      std::cout << "min 10 et 15 : " << min(10, 15) << std::endl;
    }
    {
     int a = 2;
     int b = 3;

     ::swap( a, b );
     std::cout << "a = " << a << ", b = " << b << std::endl;
     std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
     std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
     std::string c = "ahaine1";
     std::string d = "chaine2";
     ::swap(c, d);
     std::cout << "c = " << c << ", d = " << d << std::endl;
     std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
     std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
  return 0;
}
