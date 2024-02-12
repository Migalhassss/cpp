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
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const & other) : Animal(other)
{
	*this = other;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const & other)
{
	this->type = other.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog sound!!! WOOF WOOF" << std::endl;
}