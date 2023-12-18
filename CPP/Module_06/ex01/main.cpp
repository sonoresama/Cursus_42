/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:18:53 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/17 19:29:23 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int	main(void)
{
	Data data;
	Data *ptr = &data;
	std::uintptr_t uni;

	uni = Serializer::serialize(ptr);
	ptr = Serializer::deserialize(uni);
	std::cout << data.getInt() << std::endl;
	std::cout << data.getStr() << std::endl;
	std::cout << ptr->getInt() << std::endl;
	std::cout << ptr->getStr() << std::endl;
	return (0);
}
