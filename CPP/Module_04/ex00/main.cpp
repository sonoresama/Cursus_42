/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:19:46 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/03 16:59:46 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

//int main()
//{
//	const Animal* meta = new Animal();
//	const Animal* j = new Dog();
//	const Animal* i = new Cat();
//	const WrongAnimal* u = new WrongAnimal();
//	const WrongAnimal* v = new WrongCat();
//
//	std::cout << std::endl;
//	std::cout << "Animal : " << meta->_getType() << " " << std::endl;
//	meta->makeSound();
//	std::cout << "Dog : " << j->_getType() << " " << std::endl;
//	j->makeSound();
//	std::cout << "Cat : "<< i->_getType() << " " << std::endl;
//	i->makeSound(); //will output the cat sound!
//	std::cout << "Wrong Animal : " << v->_getType() << " " << std::endl;
//	u->makeSound();
//	std::cout << "Wrong Cat : " << v->_getType() << " " << std::endl;
//	v->makeSound();
//	std::cout << std::endl;
//	delete (meta);
//	delete (i);
//	delete (j);
//	delete (u);
//	delete (v);
//	return(0);
//}

int	main(void)
{
	const Animal* animal = new Animal();
	std::cout << "Hi, I am a " << animal->_getType() << " " << std::endl;
	animal->makeSound();
	delete animal;
	std::cout << std::endl;


	const Animal* dog = new Dog();
	std::cout << "Hi, I am a " << dog->_getType() << " " << std::endl;
	dog->makeSound();
	delete dog;
	std::cout << std::endl;


	const Animal* cat = new Cat();
	std::cout << "Hi, I am a " << cat->_getType() << " " << std::endl;
	cat->makeSound();
	delete cat;
	std::cout << std::endl;


	const WrongAnimal* wrong_animal = new WrongAnimal();
	std::cout << "Hi, I am a " << wrong_animal->_getType() << " " << std::endl;
	wrong_animal->makeSound();
	delete wrong_animal;
	std::cout << std::endl;


	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << "Hi, I am a " << wrong_cat->_getType() << " " << std::endl;
	wrong_cat->makeSound();
	delete wrong_cat;
	std::cout << std::endl;

	return (0);
}
