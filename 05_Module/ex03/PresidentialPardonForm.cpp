/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:27:27 by micarrel          #+#    #+#             */
/*   Updated: 2024/04/29 16:27:27 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5)
{
	this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & other) : AForm("PresidentialPardonForm", 25, 5)
{
	*this = other;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const & other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return (*this);
}

AForm *PresidentialPardonForm::returnNew(std::string target) const
{
	return (new PresidentialPardonForm(target));
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecuteGrade())
	{
		throw AForm::GradeTooLowException();
	}
	else if (!this->getSigned())
	{
		std::cerr << "Error: form not signed" << std::endl;
		return ;
	}
	AForm::execute(executor);
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
