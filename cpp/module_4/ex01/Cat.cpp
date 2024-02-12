/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:48:40 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/10 19:48:40 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	brain = new Brain();
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(Cat const & other) : Animal(other)
{
	brain = new Brain();
	*this = other;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(Cat const & other)
{
	this->type = other.type;
	*brain = *other.brain;	
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat sound!!! MEOW MEOW" << std::endl;
}

void Cat::setBIdea(int i, std::string idea)
{
	brain->setIdea(i, idea);
}

void Cat::printBIdea(int i) const
{
	brain->printIdea(i);
}
