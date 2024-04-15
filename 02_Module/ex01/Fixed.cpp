/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:35:43 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/13 13:48:17 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->nb = 0;
    std::cout <<"Default constructor called" << std::endl;
}


Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->setRawBits(value << Bits);
}

Fixed::Fixed(const float value)
{
    std::cout << "Float constructor called" << std::endl;
    this->setRawBits(roundf(value * (1 << Bits)));
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return *this;
}

int Fixed::getRawBits(void) const
{
    return nb;
}

void Fixed::setRawBits(int const raw)
{
    this->nb = raw;
}

float		Fixed::toFloat(void) const
{
	return (float)this->getRawBits() / (1 << Bits);
}

int		Fixed::toInt ( void ) const
{
	return this->getRawBits() >> Bits;
}

//overload operator
std::ostream &	operator<<(std::ostream & out, Fixed const & nb)
{
	out << nb.toFloat();
	return out;
}
