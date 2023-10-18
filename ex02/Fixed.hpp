/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:32:50 by zsyyida           #+#    #+#             */
/*   Updated: 2023/10/18 22:39:38 by zsyyida          ###   ########.fr       */
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
		
		// comparison operators
			// if operator function is defined in class first argument is obviosly object of that class 
			// (left hand side parameter)so we can define operator with only the right hand side parameter
			// comparision operators unlike in global ones.
			// const at end of function means that operator function will not change any members of class and before parameter
			// means that parameter will not be changed inside function
			// comparision returns bool  as either true or false
		bool operator>(const Fixed& object) const;
		bool operator<(const Fixed& object) const;
		bool operator>=(const Fixed& object) const;
		bool operator<=(const Fixed& object) const;
		bool operator==(const Fixed& object) const;
		bool operator!=(const Fixed& object) const;

		// arithmetic operators
		
			// const before parameter means that parameter will not be changed inside function
		Fixed operator+(const Fixed& object);
		Fixed operator-(const Fixed& object);
		Fixed operator*(const Fixed& object);
		Fixed operator/(const Fixed& object);

		// increment decrement operators

		Fixed operator++(); // pre increment
		Fixed operator++(int); //post increment
		Fixed operator--(); // pre deccrement
		Fixed operator--(int); // post decrement

        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

		static Fixed min(Fixed& object1, Fixed& object2);
		static Fixed min(const Fixed& object1, const Fixed& object2);
		static Fixed max(Fixed& object1, Fixed& object);
		static Fixed max(const Fixed& object1, const Fixed& object2);
};
// This operator overload needs 2 operands bc global and not inside class
std::ostream &operator<<( std::ostream &os, const Fixed &f);
#endif