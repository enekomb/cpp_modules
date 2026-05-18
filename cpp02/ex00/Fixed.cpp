/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:36:14 by eneko             #+#    #+#             */
/*   Updated: 2025/03/03 16:26:59 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

// Constructor por defecto
Fixed::Fixed() : _value(0) 
{
    std::cout << "Default constructor called" << std::endl;
}

// Constructor de copia / devuele una copia de un objeto ya existente
Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

// Operador de asignación por copia / cambiar el valor de un objeto a otro ya existente.
Fixed& Fixed::operator=(const Fixed &other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return (*this);
}

// Destructor
Fixed::~Fixed() 
{
    std::cout << "Destructor called" << std::endl;
}

// Función miembro para obtener el valor crudo
int Fixed::getRawBits() const 
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->_value);
}

// Función miembro para establecer el valor crudo
void Fixed::setRawBits(int const raw) 
{
    this->_value = raw;
}
