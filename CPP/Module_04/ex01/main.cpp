/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emileorer <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 13:19:46 by emileorer         #+#    #+#             */
/*   Updated: 2023/12/03 17:49:04 by emileorer        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(void)
{
	Animal	* animal_array[10];
	for (unsigned int i = 0; i < 5; i++)
	{
		animal_array[i] = new Cat();
		animal_array[i + 5] = new Dog();
	}

	const Animal* animal = new Animal();
	std::cout << "Hi, I am a " << animal->_getType() << " and I don't have a Brain!" << std::endl;
	animal->makeSound();
	delete animal;
	std::cout << std::endl;


	const Dog* dog = new Dog();
	std::cout << "Hi, I am a " << dog->_getType() << " " << std::endl;
	dog->makeSound();
	std::cout << "I am thinking of: " << dog->_getIdea(0) << std::endl;
	std::cout << "I have a new idea! FOOD!\n";
	dog->_setIdea(0, "I want to eat something. FOOD");
	std::cout << "I am thinking of: " << dog->_getIdea(0) << std::endl;
	const Dog * dog_copy = new Dog(*dog);

	std::cout << "Hi, I am a " << dog_copy->_getType() << " " << std::endl;
	std::cout << "I am thinking of: " << dog_copy->_getIdea(0) << std::endl;
	std::cout << "I have a new idea! Hunting a Cat!\n";
	dog_copy->_setIdea(1, "I want to hunt a Cat. Cat");
	std::cout << "I am thinking of: " << dog_copy->_getIdea(1) << std::endl;
	dog_copy->makeSound();

	std::cout << "I am thinking of: " << dog->_getIdea(1) << std::endl;
	delete dog_copy;
	delete dog;
	std::cout << std::endl;


	const Cat* cat = new Cat();
	std::cout << "Hi, I am a " << cat->_getType() << " " << std::endl;
	std::cout << "I am thinking of: " << cat->_getIdea(0) << std::endl;
	std::cout << "I have a new idea! FOOD!\n";
	cat->_setIdea(0, "I want to eat something. FOOD");
	std::cout << "I am thinking of: " << cat->_getIdea(0) << std::endl;
	cat->makeSound();
	const Cat * cat_copy = new Cat(*cat);
	delete cat;
	std::cout << "Hi, I am a " << cat_copy->_getType() << " " << std::endl;
	std::cout << "I am thinking of: " << cat_copy->_getIdea(0) << std::endl;
	std::cout << "I have a new idea! Hunting a Mouse!\n";
	cat_copy->_setIdea(1, "I want to hunt a Mouse. Mouse");
	std::cout << "I am thinking of: " << cat_copy->_getIdea(1) << std::endl;
	cat_copy->makeSound();
	delete cat_copy;
	std::cout << std::endl;


	const WrongAnimal* wrong_animal = new WrongAnimal();
	std::cout << "Hi, I am a " << wrong_animal->_getType() << " " << std::endl;
	std::cout << "I don't have a Brain yet. :-(\n";
	wrong_animal->makeSound();
	delete wrong_animal;
	std::cout << std::endl;


	const WrongAnimal* wrong_cat = new WrongCat();
	std::cout << "Hi, I am a " << wrong_cat->_getType() << " " << std::endl;
	std::cout << "I don't have a Brain yet too. :-((\n";
	wrong_cat->makeSound();
	delete wrong_cat;
	std::cout << std::endl;

	for (unsigned int i = 0; i < 5; i++)
	{
		delete animal_array[i];
		delete animal_array[i + 5];
	}
	return (0);
}

