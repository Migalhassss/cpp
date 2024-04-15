/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:35:42 by micarrel          #+#    #+#             */
/*   Updated: 2024/01/22 18:35:42 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->index = 0;
}

void	PhoneBook::add_contact(void)
{
	std::string	input;
	Contact		contact;

	if (index == 8)
		index = 0;
	while (1)
	{
		std::cout << "First name: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "First name can't be empty" << std::endl;
		else
		{
			this->contacts[index].set_first_name(input);
			break ;
		}
	}
	while (1)
	{
		std::cout << "Last name: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Last name can't be empty" << std::endl;
		else
		{
			this->contacts[index].set_last_name(input);
			break ;
		}
	}
	while (1)
	{
		std::cout << "Nickname: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Nickname can't be empty" << std::endl;
		else
		{
			this->contacts[index].set_nickname(input);
			break ;
		}
	}
	while (1)
	{
		std::cout << "Phone number: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Phone number can't be empty" << std::endl;
		else
		{
			this->contacts[index].set_phone_number(input);
			break ;
		}
	}
	while (1)
	{
		std::cout << "Darkest secret: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Darkest secret can't be empty" << std::endl;
		else
		{
			this->contacts[index].set_darkest_secret(input);
			break ;
		}
	}
	std::cout << "Contact added" << std::endl;
	index++;
}

int	PhoneBook::CheckContact(int i)
{
	if (this->contacts[i].get_first_name() == "")
		return 0;
	return (1);
}

void	PhoneBook::search_contact(void)
{
	int			i;
	std::string	input;

	i = 0;
	if (index == 0)
	{
		std::cout << "No contact to display" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	while (i < 8 && (CheckContact(i)))
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << this->contacts[i].get_first_name() << "|";
		std::cout << std::setw(10) << this->contacts[i].get_last_name() << "|";
		std::cout << std::setw(10) << this->contacts[i].get_nickname() << std::endl;
		i++;
	}
	while (1)
	{
		std::cout << "Enter the index of the contact you want to display: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "Index can't be empty" << std::endl;
		else if (input.length() > 1 || input[0] < '0' || input[0] > '7')
			std::cout << "Index must be between 0 and 7" << std::endl;
		else if (input[0] - '0' >= index && (CheckContact(input[0] - '0') == 0))
			std::cout << "Index doesn't exist" << std::endl;
		else
		{
			this->contacts[input[0] - '0'].display_contact();
			break ;
		}
	}
}