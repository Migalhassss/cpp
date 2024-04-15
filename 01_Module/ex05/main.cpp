/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:45:44 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/01 17:45:44 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "harl.hpp"

int main()
{
	Harl yes;

	yes.complain("DEBUG");
	yes.complain("INFO");
	yes.complain("WARNING");
	yes.complain("ERROR");
	yes.complain("ola");
}