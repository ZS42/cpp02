/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:32:20 by zsyyida           #+#    #+#             */
/*   Updated: 2023/10/17 23:43:07 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int fixed_point_value;
        static const int fractional_bits = 8;
    public:
        // Initialize your object with Constructor
        Fixed();
        // Copy the data from 'object' to 'this'
        // Perform a deep copy of any dynamically allocated resources
        // with Copy Constructor
        Fixed(const Fixed& object);
        // Release any resources held by 'this'
        // Copy the data from 'object' to 'this'
        // Perform a deep copy of dynamically allocated resources
        // with Copy Assignment Operator (overload)
        Fixed& operator=(const Fixed& object);
        ~Fixed();
        // returns the raw value of the fixed-point value.
        int getRawBits( void ) const;
        //  sets the raw value of the fixed-point number.
        void setRawBits( int const raw );
};
#endif