/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:41:57 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/11 18:41:57 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "includes.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const & other);
		virtual ~Cure();
		Cure &operator=(Cure const & other);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif