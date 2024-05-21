/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:17:46 by micarrel          #+#    #+#             */
/*   Updated: 2024/04/22 15:58:59 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	std::cout << "Bureaucrat " << this->name << " constructor created" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name1, int grade1) : name(name1)
{
	if (grade1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade = grade1;
	std::cout << "Bureaucrat " << name << " type constructer created" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->name << " destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const & other)
{
	if (this != &other)
	{
		this->grade = other.grade;
	}
	return (*this);
}

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int		Bureaucrat::getGrade() const
{
	return (this->grade);
}

void	Bureaucrat::signForm(AForm &form)
{
	if (grade <= form.getSignedGrade() && form.getSigned() == false)
	{
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	else
	{
		std::cout << name << " couldn't sign " << form.getName() << " because ";
		if (grade > form.getExecuteGrade() && grade > form.getSignedGrade())
			std::cout << "- grade is lower: Execute and Signed Grade";
		else if (grade > form.getExecuteGrade())
			std::cout << "- grade is lower: Execute Grade";
		else if (grade > form.getSignedGrade())
			std::cout << "- grade is lower: Signed Grade";
		else if (form.getSigned() == true)
			std::cout << "- form is not signed";
		else
			std::cout << "- unknown reason";
		std::cout << std::endl;
	}
}

void	Bureaucrat::incrementGrade()
{
	if (this->grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}
	
void	Bureaucrat::decrementGrade()
{
	if (this->grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &ref)
{
	os << ref.getName() << "bureaucrat grade " << ref.getGrade();
	return (os);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

void	Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executes " << form.getName() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << this->name << " couldn't execute " << form.getName() << " because " << e.what();
		if (grade > form.getExecuteGrade())
			std::cout << "- grade is lower: Execute Grade" << std::endl;
		else if (form.getSigned() == false)
			std::cout << "- form is not signed" << std::endl;
		else
			std::cout << "- unknown reason" << std::endl;
	}
}