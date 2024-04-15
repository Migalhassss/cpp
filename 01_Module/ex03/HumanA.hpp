/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:38:46 by micarrel          #+#    #+#             */
/*   Updated: 2024/01/28 18:38:46 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_H
# define HUMANA_H

#include <iostream>
#include <string>

#include "Weapon.hpp"


class HumanA
{
	private:
		std::string name;
		Weapon &weapon;
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();

		void attack();
};

#endif