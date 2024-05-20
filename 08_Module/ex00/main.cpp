/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:15:23 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/20 15:15:23 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	std::list<int> lst;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
		lst.push_back(i);
	}
	try
	{
		std::cout << *easyfind(vec, 5) << std::endl;
		std::cout << *easyfind(lst, 5) << std::endl;
		std::cout << *easyfind(lst, 10) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Not found" << std::endl;
	}
	return 0;
}