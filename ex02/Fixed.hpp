/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student42abudhabi.ae>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:32:50 by zsyyida           #+#    #+#             */
/*   Updated: 2023/10/18 16:24:19 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int fixed_point_value;
        static const int fractional_bits = 8;
    public:
        Fixed();
        Fixed(const int integer);
        Fixed(const float floating_point);
        Fixed(const Fixed& object);
        Fixed& operator=(const Fixed& object);

		// comparision operators

		Fixed& operator>(const Fixed& object);
		Fixed& operator<(const Fixed& object);
		Fixed& operator>=(const Fixed& object);
		Fixed& operator<=(const Fixed& object);
		Fixed& operator==(const Fixed& object);
		Fixed& operator!=(const Fixed& object);

		// arithmetic operators

		Fixed& operator+(const Fixed& object);
		Fixed& operator-(const Fixed& object);
		Fixed& operator*(const Fixed& object);
		Fixed& operator/(const Fixed& object);

		// increment decrement operators

		Fixed& operator++()(const Fixed& object);
		Fixed& operator++(int)(const Fixed& object);
		Fixed& operator--()(const Fixed& object);
		Fixed& operator--(int)(const Fixed& object);

        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

		Fixed staticMin(Fixed& object1, Fixed& object);
		Fixed staticMin(const Fixed& object1, const Fixed& object);
		Fixed staticMax(Fixed& object1, Fixed& object);
		Fixed staticMax(const Fixed& object1, const Fixed& object);
};

std::ostream &operator<<( std::ostream & out, const Fixed &f);
#endif