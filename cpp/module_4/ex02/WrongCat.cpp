/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:52:00 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/10 19:52:00 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const & other) : WrongAnimal(other)
{
	*this = other;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const & other)
{
	this->type = other.type;
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat sound!!! MEOW MEOW" << std::endl;
}

