/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 03:41:43 by micarrel          #+#    #+#             */
/*   Updated: 2024/05/11 03:41:43 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main()
{
	ScalarConverter converter;
	converter.convert("nan");
	converter.convert("42.0f");
	converter.convert("42.0");
}