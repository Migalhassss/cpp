/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:53:01 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/22 14:19:37 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;
	data.n = 42;
	data.s1 = "Hello";
	data.s2 = "World";

	
	uintptr_t raw = Serializer::serialize(&data);

	std::cout << "raw: " << raw << std::endl;

	Data* ptr = Serializer::deserialize(raw);

	std::cout << "n: " << ptr->n << std::endl;
	std::cout << "s1: " << ptr->s1 << std::endl;
	std::cout << "s2: " << ptr->s2 << std::endl;

	return 0;
}