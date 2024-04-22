/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:50:02 by micarrel          #+#    #+#             */
/*   Updated: 2024/04/22 15:58:16 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default"), _signed(false), _signed_grade(0), _execute_grade(0)
{
	std::cout << "Form " << this->_name << " constructor created" << std::endl;
}

Form::Form(std::string name, int execute_grade, int signed_grade) : _name(name), _signed_grade(signed_grade), _execute_grade(execute_grade)
{
	_signed = false;
	std::cout << "Form " << _name << " type constructor created" << std::endl;
}

Form::~Form()
{
	std::cout << "Form " << this->_name << " destructor called" << std::endl;
}
Form &Form::operator=(Form const & other)
{
	if (this != &other)
	{
		this->_signed = other._signed;
		this->_execute_grade = other._execute_grade;
		this->_signed_grade = other._signed_grade;
	}
	return (*this);
}

void	Form::beSigned(Bureaucrat &ref)
{
	if (ref.getgrade() > this->_signed_grade)
		throw GradeTooLowException();
	this->_signed = true;	
}

std::string Form::getName()
{
	return (_name);
}

bool	Form::getSigned()
{
	return (_signed);
}

int		Form::getSignedGrade()
{
	return (_signed_grade);
}

int		Form::getExecuteGrade()
{
	return (_execute_grade);
}

std::ostream &operator<<(std::ostream &os, Form &ref)
{
	os << ref.getName() << ": Signed Grade is " << ref.getSignedGrade() << " and Execute grade is " << ref.getExecuteGrade();
	return (os);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}