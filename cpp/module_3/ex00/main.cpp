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

#include "ClapTrap.hpp"

int main()
{
	ClapTrap clapTrap("IRIS");
	ClapTrap clapTrap2("MAE DA IRIS");

	clapTrap.attack("MAE DA IRIS");
	clapTrap2.takeDamage(10);
	clapTrap2.beRepaired(5);
	clapTrap2.attack("IRIS");
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(5);
	return 0;
}