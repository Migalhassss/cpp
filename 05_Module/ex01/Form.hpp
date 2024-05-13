/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 15:49:53 by micarrel          #+#    #+#             */
/*   Updated: 2024/04/18 18:14:17 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
# include <iostream>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		int					_signed_grade;
		int					_execute_grade;
	public:
		Form();
		Form(std::string name, int execute_grade, int signed_grade);
		~Form();
		Form		&operator=(Form const & other);
		void		beSigned(Bureaucrat &bureaucrat);
		std::string	getName();
		bool		getSigned();
		int			getSignedGrade();
		int			getExecuteGrade();
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<(std::ostream &os, Form &ref);

#endif
