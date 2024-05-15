/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:52:38 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/15 18:52:38 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>

void    print(T const &x)
{
	std::cout << x << std::endl;
}

template <typename T>

void    iter(T *array, int length, void (*f)(T const &))
{
	int i = 0;

	while (i < length)
	{
		f(array[i]);
		i++;
	}
}

#endif
