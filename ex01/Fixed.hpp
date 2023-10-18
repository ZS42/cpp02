/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:32:37 by zsyyida           #+#    #+#             */
/*   Updated: 2023/10/18 01:08:05 by zsyyida          ###   ########.fr       */
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
        Fixed();
        Fixed(const int integer);
        Fixed(const float floating_point);
        Fixed(const Fixed& object);
        Fixed& operator=(const Fixed& object);
        ~Fixed();
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream &operator<<( std::ostream & out, const Fixed &f);
#endif