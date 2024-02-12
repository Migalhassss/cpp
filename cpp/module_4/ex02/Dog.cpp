/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:45:28 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/10 19:45:28 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	brain = new Brain();
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const & other) : Animal(other)
{
	brain = new Brain();
	*this = other;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const & other)
{
	this->type = other.type;
	*brain = *other.brain;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog sound!!! WOOF WOOF" << std::endl;
}

void Dog::setBIdea(int i, std::string idea)
{
	brain->setIdea(i, idea);
}

void Dog::printBIdea(int i) const
{
	brain->printIdea(i);
}