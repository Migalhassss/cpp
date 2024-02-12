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
	int i = 0;
	Animal *arrayAnimal[20];

	while (i < 10)
	{
		arrayAnimal[i] = new Dog();
		arrayAnimal[i + 10] = new Cat();
		i++;
	}
	i = 0;
	while (i < 20)
	{
		arrayAnimal[i]->makeSound();
		delete arrayAnimal[i++];
	}
	Cat* cat = new Cat();
	Cat* cat2 = new Cat(*cat);


	cat->printBIdea(5);
	cat2->printBIdea(5);

	cat->setBIdea(5, "Cat1 idea 1");
	cat->printBIdea(5);
	cat2->setBIdea(5, "Cat2 idea 2");
	cat2->printBIdea(5);

	std::cout << std::endl;
	std::cout << std::endl;

	Dog basic;
	
	Dog tmp = basic;
	tmp.makeSound();
	basic.makeSound();
	tmp.setBIdea(5, "Dog1 idea 1");
	basic.setBIdea(5, "Dog2 idea 2");
	tmp.printBIdea(5);
	basic.printBIdea(5);



	std::cout << std::endl;

	delete cat;
	delete cat2;
	return 0;
}