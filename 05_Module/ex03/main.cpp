/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:22:05 by micarrel          #+#    #+#             */
/*   Updated: 2024/04/29 16:22:05 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	AForm *shrubberyForm = NULL;
	AForm *robotomyForm = NULL;
	AForm *pardonForm = NULL;

	try
	{
		Bureaucrat bob("Bob", 1);
		Intern intern;
		shrubberyForm = intern.makeForm("ShrubberyCreationForm", "home");
		robotomyForm = intern.makeForm("RobotomyRequestForm", "target");
		pardonForm = intern.makeForm("PresidentialPardonForm", "criminal");

		
		if (shrubberyForm != NULL && robotomyForm != NULL && pardonForm != NULL)
		{		
			bob.signForm(*shrubberyForm);
			bob.signForm(*robotomyForm);
			bob.signForm(*pardonForm);

			std::cout << "Test 1" << std::endl;
			bob.executeForm(*shrubberyForm);
			std::cout << std::endl;
			std::cout << "Test 2" << std::endl;
			bob.executeForm(*robotomyForm);
			std::cout << std::endl;
			std::cout << "Test 3" << std::endl;
			bob.executeForm(*pardonForm);
			std::cout << std::endl;
		}
		else
			std::cerr << "Form creation failed" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &exception)
	{
		std::cerr << "Caught GradeTooHighException: " << exception.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &exception)
	{
		std::cerr << "Caught GradeTooLowException: " << exception.what() << std::endl;
	} 
	catch (std::exception &exception)
	{
		std::cerr << "Caught exception: " << exception.what() << std::endl;
	}

	if (shrubberyForm != NULL)
		delete shrubberyForm;
	if (robotomyForm != NULL)
		delete robotomyForm;
	if (pardonForm != NULL)
		delete pardonForm;
	return 0;
}