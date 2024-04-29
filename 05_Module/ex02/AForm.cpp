/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:18:24 by micarrel          #+#    #+#             */
/*   Updated: 2024/04/29 16:18:24 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToExecute(150), _gradeToSign(150)
{
	std::cout << "AForm " << this->_name << " constructor created" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToExecute(gradeToExecute), _gradeToSign(gradeToSign)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm " << name << " type constructer created" << std::endl;
}

AForm::AForm(AForm const & other) : _name(other._name), _signed(other._signed), _gradeToExecute(other._gradeToExecute), _gradeToSign(other._gradeToSign)
{
	std::cout << "AForm " << this->_name << " copy constructor created" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm " << this->_name << " destructor called" << std::endl;
}

AForm &AForm::operator=(AForm const & other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return (*this);
}

std::string AForm::getName() const
{
	return (this->_name);
}

bool AForm::getSigned() const
{
	return (this->_signed);
}

int AForm::getSignedGrade() const
{
	return (this->_gradeToSign);
}

int AForm::getExecuteGrade() const
{
	return (this->_gradeToExecute);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream &operator<<(std::ostream &os, AForm &ref)
{
	os << ref.getName() << ": Signed Grade is " << ref.getSignedGrade() << " and Execute grade is " << ref.getExecuteGrade();
	return (os);
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->_gradeToExecute)
		throw AForm::GradeTooLowException();
	if (!this->_signed)
	{
		std::cout << "Form " << this->_name << " is not signed" << std::endl;
		return ;
	}
}

