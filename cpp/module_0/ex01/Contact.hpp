/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:43:17 by micarrel          #+#    #+#             */
/*   Updated: 2024/01/22 18:43:17 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		void		set_first_name(std::string first_name);
		std::string	get_first_name(void);
		void		set_last_name(std::string last_name);
		std::string	get_last_name(void);
		void		set_nickname(std::string nickname);
		std::string	get_nickname(void);
		void		set_phone_number(std::string phone_number);
		std::string	get_phone_number(void);
		void		set_darkest_secret(std::string darkest_secret);
		std::string	get_darkest_secret(void);
		void		display_contact(void);
};


#endif
