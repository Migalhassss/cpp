/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:48:12 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/11 18:48:12 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "includes.hpp"

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* inventory[4];
	public:
		Character();
		Character(std::string const & name);
		Character(Character const & other);
		~Character();
		Character &operator=(Character const & other);
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif