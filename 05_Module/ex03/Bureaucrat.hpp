/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:08:39 by micarrel          #+#    #+#             */
/*   Updated: 2024/04/18 18:09:37 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef BUREAUCRAT_hpp
# define BUREAUCRAT_hpp

# include <iostream>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();
		Bureaucrat &operator=(Bureaucrat const & other);
		std::string getName() const;
		int			getGrade() const;
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(AForm &form);
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
		void executeForm(AForm const & form);
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &ref);

# endif
