/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:32:46 by zsyyida           #+#    #+#             */
/*   Updated: 2023/10/18 22:35:23 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
//    std::cout << "Default constructor called" <<std::endl;
   this->fixed_point_value = 0;
}

Fixed::Fixed(const int integer):fixed_point_value(integer << fractional_bits)
{
    // std::cout << "Int constructor called" <<std::endl;
}

// roundf is used to round a floating-point number to the nearest integer.
Fixed::Fixed(const float floating_point):fixed_point_value(roundf(floating_point * (1 << fractional_bits)))
{
    // std::cout << "Float constructor called" <<std::endl;
}

Fixed::Fixed(const Fixed& object)
{
    // std::cout << "Copy constructor called" <<std::endl;
    *this = object;
}

Fixed& Fixed::operator=(const Fixed &object)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &object)
        this->fixed_point_value = object.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    return this->fixed_point_value;
}

void Fixed::setRawBits( int const raw )
{
    this->fixed_point_value = raw;
}

float Fixed::toFloat( void ) const
{
	float floating_point_value;
	// Floating-point_value = Fixed-point_value / 256.0
	// Use static cast to float to make sure you get result as a float
	floating_point_value = static_cast<float>(this->fixed_point_value) /  static_cast<float>(1 << fractional_bits);
	return floating_point_value ;
}

int Fixed::toInt( void ) const
{
	int integer;
	integer = fixed_point_value >> fractional_bits;
	return integer;
}

// For simple things like int can pass dirctly otherwise pass parameters of overload as reference
std::ostream &operator<<( std::ostream &os, const Fixed &fixed_point_value)
{
	os << fixed_point_value.toFloat();
	return os;
}

        // comparision operators
			
bool Fixed::operator>(const Fixed& object) const
{
    return this->getRawBits() > object.getRawBits();
}

bool Fixed::operator<(const Fixed& object) const
{
    return this->getRawBits() < object.getRawBits();
}

bool Fixed::operator>=(const Fixed& object) const
{
    return this->getRawBits() >= object.getRawBits();
}

bool Fixed::operator<=(const Fixed& object) const
{
    return this->getRawBits() <= object.getRawBits();
}

bool Fixed::operator==(const Fixed& object) const
{
    return this->getRawBits() == object.getRawBits();
}

bool Fixed::operator!=(const Fixed& object) const
{
    return this->getRawBits() != object.getRawBits();
}

		// arithmetic operators

Fixed Fixed::operator+(const Fixed& object)
{
    return (this->toFloat() + object.toFloat());
}

Fixed Fixed::operator-(const Fixed& object)
{
    return (this->toFloat() - object.toFloat());
}

Fixed Fixed::operator*(const Fixed& object)
{
    return (this->toFloat() * object.toFloat());
}

Fixed Fixed::operator/(const Fixed& object)
{
    return (this->toFloat() / object.toFloat());
}

		// increment decrement operators

// pre increment called prefix
Fixed Fixed::operator++()
{
    this->fixed_point_value++;
    return (*this);
}

//post increment called postfix
// here int is a dummy parameter to differentiate between pre and postfix
Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    // same as temp = *this;
    this->fixed_point_value++;
    return (temp);
}

 // pre decrement 
Fixed Fixed::operator--()
{
    this->fixed_point_value--;
    return (*this);
}

// post decrement
Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    this->fixed_point_value--;
    return (temp);
}

Fixed Fixed::min(Fixed& fp1, Fixed& fp2)
{
    if (fp1 < fp2)
        return (fp1);
    else
        return (fp2);
}

Fixed Fixed::min(const Fixed& fp1, const Fixed& fp2)
{
    if (fp1 < fp2)
        return (fp1);
    else
        return (fp2);
}

Fixed Fixed::max(Fixed& fp1, Fixed& fp2)
{
    if (fp1 > fp2)
        return (fp1);
    else
        return (fp2);
}

Fixed Fixed::max(const Fixed& fp1, const Fixed& fp2)
{
    if (fp1 > fp2)
        return (fp1);
    else
        return (fp2);
}
