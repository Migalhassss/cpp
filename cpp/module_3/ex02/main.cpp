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

#include "FragTrap.hpp"

int main()
{
	FragTrap frag("Miggy");
	frag.attack("target");
	frag.takeDamage(20);
	frag.beRepaired(10);
	frag.highFivesGuys();
	return 0;
}

