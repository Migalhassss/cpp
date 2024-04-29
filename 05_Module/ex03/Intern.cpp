/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 18:07:02 by micarrel          #+#    #+#             */
/*   Updated: 2024/04/29 18:07:02 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	forms[0] = new PresidentialPardonForm();
	forms[1] = new RobotomyRequestForm();
	forms[2] = new ShrubberyCreationForm();
}

Intern::Intern(Intern const & other)
{
	(void)other;

	forms[0] = new PresidentialPardonForm();
	forms[1] = new RobotomyRequestForm();
	forms[2] = new ShrubberyCreationForm();
}

Intern::~Intern()
{
	for (int i = 0; i < 3; i++)
		delete forms[i];
}

Intern &Intern::operator=(Intern const & other)
{
	(void)other;

	return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	std::string formNames[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i]->returnNew(target);
		}
	}
	std::cout << "Intern doesn't know this form" << std::endl;
	return NULL;
}

