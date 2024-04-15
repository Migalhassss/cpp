/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:53:17 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/10 19:53:17 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongCat1 = new WrongCat();
	const WrongAnimal* wrongCat2 = new WrongCat();

	std::cout << std::endl;
	std::cout << "animal->getType() = " << animal->getType() << std::endl;
	std::cout << "cat->getType() = " << cat->getType() << std::endl;
	std::cout << "dog->getType() = " << dog->getType() << std::endl;
	std::cout << "wrongAnimal->getType() = " << wrongAnimal->getType() << std::endl;
	std::cout << "wrongCat1->getType() = " << wrongCat1->getType() << std::endl;
	std::cout << "wrongCat2->getType() = " << wrongCat2->getType() << std::endl;
	std::cout << std::endl;

	animal->makeSound();
	cat->makeSound();
	dog->makeSound();
	wrongAnimal->makeSound();
	wrongCat1->makeSound();
	wrongCat2->makeSound();
	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;
	delete wrongAnimal;
	delete wrongCat1;
	delete wrongCat2;
	return 0;
}