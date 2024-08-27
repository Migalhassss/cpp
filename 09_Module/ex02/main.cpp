/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 03:20:41 by micarrel          #+#    #+#             */
/*   Updated: 2024/08/21 03:20:41 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool checkArgs(int argc, char* argv[])
{
	int i = 1;
	while (i < argc)
	{
		int j = 0;
		while (argv[i][j])
		{
			if (!isdigit(argv[i][j]) && argv[i][j] != ' ')
			{
				std::cout << "Invalid argument" << std::endl;
				return false;
			}
			else if (isdigit(argv[i][j]) && (argv[i][j] - '0') > 9)
			{
				std::cout << "Invalid argument" << std::endl;
				return false;
			}
			j++;
		}
		i++;
	}
	return true;
}

int main(int argc, char* argv[])
{

	if (checkArgs(argc, argv) == false)
		return 1;
	PmergeMe pmergeMe;
	pmergeMe.sortAndPrint(argc, argv);
	return 0;
}