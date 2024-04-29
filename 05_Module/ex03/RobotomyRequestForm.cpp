/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:23:22 by micarrel          #+#    #+#             */
/*   Updated: 2024/04/29 16:23:22 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 1, 1), _target("default")
{
	this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 1, 1), _target(target)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & other) : AForm(other), _target(other._target)
{
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const & other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
}

AForm *RobotomyRequestForm::returnNew(std::string target) const
{
	return (new RobotomyRequestForm(target));
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	else if (this->getSigned() == false)
	{
		std::cout << "Form is not signed" << std::endl;
		return ;
	}
	else
	{
		std::cout << "Bzzzzzz Bzzzzzz Bzzzzzz" << std::endl;
		if (rand() % 2 == 0)
			std::cout << this->_target << " has been robotomized successfully" << std::endl;
		else
			std::cout << this->_target << " robotomization failed" << std::endl;
	}
}