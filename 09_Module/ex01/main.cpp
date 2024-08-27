/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 19:07:01 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/24 19:51:03 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./RPN \"[RPN expression]\"" << std::endl;
		return 1;
	}
	if (!checkInput(av[1]))
	{
		std::cout << "Invalid input" << std::endl;
		return 1;
	}
	rpn(av[1]);
	return 0;
}