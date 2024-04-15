/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:16:25 by micarrel          #+#    #+#             */
/*   Updated: 2024/01/22 18:16:25 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

void	print_options(void)
{
	std::cout << std::endl;
	std::cout << "Type | ADD	| to save a new contact" << std::endl;
	std::cout << "Type | SEARCH	| to display the contacts" << std::endl;
	std::cout << "Type | EXIT	| to exit the program lol" << std::endl;
	std::cout << "Waiting for input: ";
}

int main(void)
{
	std::string	input;
	PhoneBook	phonebook;

	while (1)
	{
		print_options();
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_contact();
		else if (input == "EXIT")
			break ;
		else
			std::cout << "Wrong input" << std::endl;
	}
}