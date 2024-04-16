/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 16:09:03 by micarrel          #+#    #+#             */
/*   Updated: 2024/04/16 19:18:03 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

int main()
{
	int grade = 20;

	try
	{
		Bureaucrat bureaucrat("yes", grade);
		std::cout << bureaucrat.getname() << " has a grade of " << bureaucrat.getgrade() << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat.getname() << " has a grade of " << bureaucrat.getgrade() << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat.getname() << " has a grade of " << bureaucrat.getgrade() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}	