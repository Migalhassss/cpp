/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:48:55 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/11 18:48:55 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	std::cout << "Character default constructor called" << std::endl;
	int i = 0;
	this->name = "default";
	while (i < 4)
		this->inventory[i++] = NULL;
}

Character::Character(std::string const & name)
{
	std::cout << "Character constructor called" << std::endl;
	int i = 0;
	this->name = name;
	while (i < 4)
		this->inventory[i++] = NULL;
}

Character::Character(Character const & other)
{
	std::cout << "Character copy constructor called" << std::endl;
	*this = other;
}

Character::~Character()
{
	std::cout << "Character destructor called" << std::endl;
	int i = 0;
	while (i < 4)
	{
		delete this->inventory[i];
		i++;
	}
}

Character &Character::operator=(Character const & other)
{
	std::cout << "Character assignation operator called" << std::endl;
	int i = 0;
	this->name = other.name;
	while (i < 4)
	{
		if (this->inventory[i])
			delete this->inventory[i];
		this->inventory[i] = other.inventory[i]->clone();
		i++;
	}
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
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

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && this->inventory[idx])
		this->inventory[idx]->use(target);
}
