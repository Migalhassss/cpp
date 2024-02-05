/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:11:16 by micarrel          #+#    #+#             */
/*   Updated: 2024/01/28 15:11:16 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	int nb = 6;
	Zombie *zombies = zombieHorde(nb, "Miggy");

	while (nb--)
		zombies[nb].announce();
	delete[] zombies;
	return (0);
}
