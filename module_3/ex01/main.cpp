/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 20:57:19 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/09 20:57:19 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
	ClapTrap trap("Clap");
	trap.attack("Target");
	trap.takeDamage(50);
	trap.beRepaired(5);
	std::cout << std::endl << std::endl;
	ScavTrap scav("Scav");
	scav.attack("Target");
	scav.guardGate();
	scav.takeDamage(30);
	scav.beRepaired(10);
}

