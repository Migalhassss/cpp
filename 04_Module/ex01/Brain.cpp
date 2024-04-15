/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:14:19 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/10 20:14:19 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() : ideas()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const & other)
{
	*this = other;
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const & other)
{
	int i = 0;
	while (i < 100)
	{
		this->ideas[i] = other.ideas[i];
		i++;
	}
	return *this;
}

void Brain::setIdea(int i, std::string idea)
{
	ideas[i] = idea;
}

void Brain::printIdea(int i) const
{
	std::cout << ideas[i] << std::endl;
}