/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:35:58 by micarrel          #+#    #+#             */
/*   Updated: 2024/01/22 18:35:58 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		int			index;
		Contact		contacts[8];
	public:
		PhoneBook();
		void	add_contact(void);
		void	search_contact(void);
		int	CheckContact(int i);
};

#endif