/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:52:40 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/15 18:52:40 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main ()
{
	int tab[] = {0, 1, 2, 3, 4};
	::iter(tab, 5, ::print);

	std::cout << std::endl;
	std::string tab2[] = {"salut", "les", "amis", "!"};
	::iter(tab2, 4, ::print);
	return 0;
}