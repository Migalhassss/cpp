/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:24:00 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/10 23:24:00 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "AMateria";
	std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	this->type = type;
	std::cout << "AMateria type constructor called" << std::endl;
}

AMateria::AMateria(AMateria const & other)
{
	*this = other;
	std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

AMateria &AMateria::operator=(AMateria const & other)
{
	this->type = other.type;
	return *this;
}

std::string const & AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter & target)
{
	(void)target;
}

