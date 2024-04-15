/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:35:43 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/13 13:57:42 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->nb = 0;
}


Fixed::Fixed(const int value)
{
    this->setRawBits(value << Bits);
}

Fixed::Fixed(const float value)
{
    this->setRawBits(roundf(value * (1 << Bits)));
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
}

Fixed::~Fixed()
{
}

Fixed &Fixed::operator=(const Fixed &other) 
{
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return *this;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->toFloat() > other.toFloat();
}

bool Fixed::operator<(const Fixed &other) const
{
    std::cout << "this->toFloat() = " << this->toFloat() << std::endl;
    return this->toFloat() < other.toFloat();
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->toFloat() >= other.toFloat();
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->toFloat() <= other.toFloat();
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->toFloat() != other.toFloat();
}

Fixed &Fixed::operator++(void)
{
    this->nb++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--(void)
{
    this->nb--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    operator--();
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}


const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
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
