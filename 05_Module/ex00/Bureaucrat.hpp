/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:08:39 by micarrel          #+#    #+#             */
/*   Updated: 2024/04/17 17:48:08 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef BUREAUCRAT_hpp
# define BUREAUCRAT_hpp

# include <iostream>

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
		std::string getname() const;
		int			getgrade() const;
		void		incrementGrade();
		void		decrementGrade();
		
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

std::ostream &operator<<(std::ostream &os, Bureaucrat &ref);

# endif
