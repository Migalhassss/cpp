/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 12:58:43 by micarrel          #+#    #+#             */
/*   Updated: 2024/08/19 19:18:06 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage : ./btc <file.txt>" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange ExChange(av[1]);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
		return (1);
	}
}