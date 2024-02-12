/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:55:53 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/11 18:55:53 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;

	std::cout << std:: endl;
	std::cout << std:: endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(0);
	me->use(0, *bob);
	me->use(1, *bob);
	me->equip(tmp);

	std::cout << std:: endl;
	std::cout << std:: endl;
	delete bob;
	delete me;
	delete src;
	return 0;
}

