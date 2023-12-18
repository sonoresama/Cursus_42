/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:57:00 by eorer             #+#    #+#             */
/*   Updated: 2023/12/18 14:26:14 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename U>

void	iter(T* ptr, U length, void(*f)(T& data))
{
  for (int i = 0; i < length; i++)
	f(ptr[i]);
  return ;
}
