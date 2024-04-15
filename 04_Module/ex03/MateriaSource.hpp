/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:53:41 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/11 18:53:41 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* inventory[4];
	public:
		MateriaSource();
		MateriaSource(MateriaSource const & other);
		virtual ~MateriaSource();
		MateriaSource &operator=(MateriaSource const & other);
		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const & type);
};

#endif