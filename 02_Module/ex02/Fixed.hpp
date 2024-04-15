/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: micarrel <micarrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 05:30:55 by micarrel          #+#    #+#             */
/*   Updated: 2024/02/09 05:24:52 by micarrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <iomanip>
# include <cmath>

class Fixed
{
    private:
        int nb;
        static const int Bits = 8;
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &copy);
        Fixed(const int value);
        Fixed(const float value);
 
        Fixed &operator=(const Fixed &other);
        Fixed operator+(const Fixed &other) const;
        Fixed operator-(const Fixed &other) const;
        Fixed operator*(const Fixed &other) const;
        Fixed operator/(const Fixed &other) const;

        bool operator>(const Fixed &other) const;
        bool operator<(const Fixed &other) const;
        bool operator>=(const Fixed &other) const;
        bool operator<=(const Fixed &other) const;
        bool operator==(const Fixed &other) const;
        bool operator!=(const Fixed &other) const;

        // pre-incrementation
        Fixed &operator++(void);
        // post-incrementation
        Fixed operator++(int);
        // pre-decrementation
        Fixed &operator--(void);
        // post-decrementation
        Fixed operator--(int);

        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);    

        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat(void) const;
        int toInt(void) const; 
};

std::ostream &	operator<<(std::ostream & out, Fixed const & nb);

#endif