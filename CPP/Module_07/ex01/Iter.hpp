/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eorer <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:57:00 by eorer             #+#    #+#             */
/*   Updated: 2024/01/16 16:56:10 by eorer            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T, typename U, typename V>
void	iter(T* ptr, U length, void(*f)(V data))
{
  for (U i = 0; i < length; i++)
	f(ptr[i]);
  return ;
}
