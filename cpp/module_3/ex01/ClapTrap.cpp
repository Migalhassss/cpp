/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 21:21:24 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/09 21:21:24 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDamage = 0;
}

ClapTrap &ClapTrap::operator=(ClapTrap const & other)
{
	this->name = other.name;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	this->attackDamage = other.attackDamage;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(std::string const & target)
{
	std::cout << "ClapTrap " << this->name << " attack " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints -= 1;
}


void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " take " << amount << " points of damage!" << std::endl;
	this->hitPoints -= amount;	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name << " be repaired for " << amount << " points of damage!" << std::endl;
	this->hitPoints += amount;
	this->energyPoints -= 1;
}

int ClapTrap::getHitPoints()
{
	return this->hitPoints;
}

void ClapTrap::setHitPoints(int hitPoints)
{
	this->hitPoints = hitPoints;
}

int ClapTrap::getEnergyPoints()
{
	return this->energyPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints)
{
	this->energyPoints = energyPoints;
}

