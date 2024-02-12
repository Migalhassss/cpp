/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 20:11:48 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/10 20:11:48 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string ideas[100];
	public:
		Brain();
		Brain(Brain const & other);
		~Brain();
		Brain &operator=(Brain const & other);
		void printIdea(int i) const;
		void setIdea(int i, std::string idea);
};

#endif