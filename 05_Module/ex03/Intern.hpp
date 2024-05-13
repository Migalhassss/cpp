/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:55:41 by micarrel          #+#    #+#             */
/*   Updated: 2024/04/29 17:55:41 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Intern
{
	private:
		AForm	*forms[3];
	public:
		Intern();
		Intern(std::string name);
		Intern(Intern const & other);
		~Intern();
		Intern &operator=(Intern const & other);
		AForm	*makeForm(std::string form, std::string target);
};

#endif