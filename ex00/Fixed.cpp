/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:32:14 by zsyyida           #+#    #+#             */
/*   Updated: 2023/10/18 00:08:10 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
   std::cout << "Default constructor called" <<std::endl;
   this->fixed_point_value = 0;
}

Fixed::Fixed(const Fixed& object)
{
    std::cout << "Copy constructor called" <<std::endl;
    *this = object;
    // this->fixed_point_value = object.fixed_point_value;
}

Fixed& Fixed::operator=(const Fixed &object)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &object)
    {
        return *this;
    }
    this->fixed_point_value = object.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixed_point_value;
}

void Fixed::setRawBits( int const raw )
{
    this->fixed_point_value = raw;
}