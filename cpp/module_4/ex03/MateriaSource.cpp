/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:54:23 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/11 18:54:23 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource constructor called" << std::endl;
	int i = 0;
    while (i < 4)
        this->inventory[i++] = NULL;

}

MateriaSource::MateriaSource(MateriaSource const & other)
{
	std::cout << "MateriaSource copy constructor called" << std::endl;
	*this = other;
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource destructor called" << std::endl;
	int i = 0;
	while (i < 4)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		i++;
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const & other)
{
	std::cout << "MateriaSource assignation operator called" << std::endl;
	int i = 0;
	while (i < 4)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		this->inventory[i] = other.inventory[i]->clone();
		i++;
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m)
{
	int i = 0;
	while (i < 4)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			break;
		}
		i++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	while (i < 4)
	{
		if (this->inventory[i] && this->inventory[i]->getType() == type)
			return (this->inventory[i]->clone());
		i++;
	}
	return (NULL);
}