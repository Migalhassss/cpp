/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:50:48 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/10 19:50:48 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->type = type;
	std::cout << "WrongAnimal type constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const & other)
{
	this->type = other.type;
	return *this;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound!!!" << std::endl;
}	
