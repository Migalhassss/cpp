/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:39:19 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/11 18:39:19 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice constructor called" << std::endl;
	this->type = "ice";
}

Ice::Ice(Ice const & other) : AMateria("ice")
{
	std::cout << "Ice copy constructor called" << std::endl;
	*this = other;
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
}

Ice &Ice::operator=(Ice const & other)
{
	std::cout << "Ice assignation operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

