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

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// const Animal *meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	// meta->makeSound();
	j->makeSound();
	i->makeSound();
	std::cout << std::endl;

	delete j;
	delete i;
	return 0;
}