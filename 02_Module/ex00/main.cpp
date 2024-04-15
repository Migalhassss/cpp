/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:35:41 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/13 12:41:14 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

    Fixed a;
    Fixed b( a );
    Fixed c;

    c = b;
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;


    std::cout << "-------------------" << std::endl;
    a.setRawBits(42);
    std::cout << a.getRawBits() << std::endl;
    b.setRawBits(21);
    std::cout << b.getRawBits() << std::endl;
    c.setRawBits(84);
    std::cout << c.getRawBits() << std::endl;
    return 0;
}