/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 22:09:10 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/09 22:09:10 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(std::string const & target)
{
	if (this->energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->name << " has no energy points to attack!" << std::endl;
		return;
	}
	else if (this->hitPoints <= 0)
	{
		std::cout << "ScavTrap " << this->name << " has no hit points to attack!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " attack " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints -= 1;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " have enterred in Gate keeper mode" << std::endl;
}

