/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:17:46 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/16 16:22:17 by micarrel         ###   ########.fr       */
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

std::string Bureaucrat::getname() const
{
	return (this->name);
}

int		Bureaucrat::getgrade() const
{
	return (this->grade);
}

void	Bureaucrat::signForm(Form &form)
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
	os << ref.getname() << "bureaucrat grade " << ref.getgrade();
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