/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:32:39 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/01 15:32:39 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

void	ft_replace(std::string& file, std::string& s1, std::string& s2)
{
	size_t pos = file.find(s1);

	while (pos != std::string::npos)
	{
		file.erase(pos, s1.length());
		file.insert(pos, s2);
		pos = file.find(s1, pos + s2.length());
	}
}