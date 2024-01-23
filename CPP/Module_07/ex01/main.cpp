/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:05:53 by eorer             #+#    #+#             */
/*   Updated: 2024/01/16 16:58:29 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"

  //Int
void  i_display(int& a)
{
  std::cout << a << std::endl;
}

void  i_doubleInt(int& a)
{
  a *= 2;
}

  //String
void  s_display(std::string& a)
{
  std::cout << a << std::endl;
}

void  s_upperStr(std::string& a)
{
  for (size_t i = 0; i < a.length(); i++)
    a[i] = std::toupper(a[i]);
}

int  main(void)
{
  int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::string strs[5] = {"hello", "comment", "ca", "va", "tito?"};

  ::iter(array, 10, &i_display);
  ::iter(array, 10, &i_doubleInt);
  ::iter(array, 10, &i_display);
  std::cout << std::endl;
  ::iter(strs, 5, &s_display);
  ::iter(strs, 5, &s_upperStr);
  ::iter(strs, 5, &s_display);
  return (0);
}

//static	void	fn_string(std::string val)
//{
//	std::cout << val << std::endl;
//}
//
//static	void	fn_int(int val)
//{
//	std::cout << val << std::endl;
//}
//
//static	void	fn_float(float val)
//{
//	std::cout << val << std::endl;
//}
//
//static	void	fn_double(double val)
//{
//	std::cout << val << std::endl;
//}
//
//static	void	fn_char(char val)
//{
//	std::cout << val << std::endl;
//}
//
//int main(void)
//{
//	std::cout << "---- String array ----" << std::endl;
//	std::string strArray[2] = {"Hola", "Mundo"};
//	::iter(strArray, sizeof(strArray) / sizeof(std::string), &fn_string);
//
//	std::cout << "---- Int array ----" << std::endl;
//	int intArray[2] = {1, 2};
//	::iter(intArray, sizeof(intArray) / sizeof(int), &fn_int);
//
//	std::cout << "---- Float array ----" << std::endl;
//	float floatArray[2] = { 1.02f, 2.04f };
//	::iter(floatArray, sizeof(floatArray) / sizeof(float), &fn_float);
//
//	std::cout << "---- Double array ----" << std::endl;
//	double doubleArray[2] = {1.1, 2.2};
//	::iter(doubleArray, sizeof(doubleArray) / sizeof(double), &fn_double);
//
//	std::cout << "---- Char array ----" << std::endl;
//	char charArray[2] = {'a', 'b'};
//	::iter(charArray, sizeof(charArray) / sizeof(char), *fn_char);
//	return (0);
//}
