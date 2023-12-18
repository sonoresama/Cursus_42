/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tmp.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:36:31 by eorer             #+#    #+#             */
/*   Updated: 2023/12/18 13:47:15 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template < typename T >
void  swap(T& a, T& b)
{
  T tmp = a;

  a = b;
  b = tmp;
}

template < typename T >
const T&  min(const T& a, const T& b)
{
  if (b > a)
    return (a);
  return (b);
}

template < typename T >
const T&  max(const T& a, const T& b)
{
  if (a > b)
    return (a);
  return (b);
}
