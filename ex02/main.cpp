/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsyyida <zsyyida@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:32:58 by zsyyida           #+#    #+#             */
/*   Updated: 2023/10/19 00:23:17 by zsyyida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) 
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << "extra test " << --a << std::endl;
    std::cout << "extra test " << a << std::endl;
    std::cout << "extra test " << a-- << std::endl;
    std::cout << "extra test " << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << "extra test " << Fixed::min( a, b ) << std::endl;
    Fixed const c( Fixed( 5.05f ) + Fixed( 2 ) );
    std::cout << "extra test " << c << std::endl;
    Fixed const d( Fixed( 5.05f ) - Fixed( 2 ) );
    std::cout << "extra test " << d << std::endl;
    Fixed const e( Fixed( 5.05f ) / Fixed( 2 ) );
    std::cout << "extra test " << e << std::endl;
    Fixed const f( Fixed( 5.05f ) * Fixed( 2 ) );
    if (d > e)
        std::cout << "extra test > " << std::endl;
    if (e < d)   
        std::cout << "extra test <" << std::endl;
    if (e >= d)    
        std::cout << "extra test >=" << std::endl;
    if (e <= d)    
        std::cout << "extra test <=" << std::endl;
    if  (b == f)  
        std::cout << "extra test ==" << std::endl;
    if (e != d)    
        std::cout << "extra test !=" << std::endl;
    
    return 0;
}
