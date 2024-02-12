/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 18:38:13 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/11 18:38:13 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "includes.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const & other);
		virtual ~Ice();
		Ice &operator=(Ice const & other);
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif