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
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wrongmeta = new WrongAnimal();
	const WrongAnimal* wrongj = new WrongCat();
	const WrongAnimal* wrongi = new WrongCat();

	std::cout << std::endl;
	std::cout << "meta->getType() = " << meta->getType() << std::endl;
	std::cout << "j->getType() = " << j->getType() << std::endl;
	std::cout << "i->getType() = " << i->getType() << std::endl;
	std::cout << "wrongmeta->getType() = " << wrongmeta->getType() << std::endl;
	std::cout << "wrongj->getType() = " << wrongj->getType() << std::endl;
	std::cout << "wrongi->getType() = " << wrongi->getType() << std::endl;
	std::cout << std::endl;

	meta->makeSound();
	j->makeSound();
	i->makeSound();
	wrongmeta->makeSound();
	wrongj->makeSound();
	wrongi->makeSound();
	std::cout << std::endl;

	delete meta;
	delete j;
	delete i;
	delete wrongmeta;
	delete wrongj;
	delete wrongi;
	return 0;
}