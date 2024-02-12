/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 19:48:17 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/10 19:48:17 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain *brain;
	public:
		Cat();
		Cat(Cat const & other);
		~Cat();
		Cat &operator=(Cat const & other);
		void makeSound() const;
		void printBIdea(int i) const;
		void setBIdea(int i, std::string idea);
};

#endif