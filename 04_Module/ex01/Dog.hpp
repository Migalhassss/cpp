/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:43:50 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/10 19:43:50 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain *brain;
	public:
		Dog();
		Dog(Dog const & other);
		~Dog();
		Dog &operator=(Dog const & other);
		void makeSound() const;
		void printBIdea(int i) const;
		void setBIdea(int i, std::string idea);
};

# endif