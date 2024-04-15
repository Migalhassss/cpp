/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:42:05 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/11 18:42:05 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure constructor called" << std::endl;
	this->type = "cure";
}

Cure::Cure(Cure const & other) : AMateria("cure")
{
	std::cout << "Cure copy constructor called" << std::endl;
	*this = other;
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
}

Cure &Cure::operator=(Cure const & other)
{
	std::cout << "Cure assignation operator called" << std::endl;
	this->type = other.type;
	return (*this);
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}