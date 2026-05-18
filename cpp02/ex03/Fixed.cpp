/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:36:14 by eneko             #+#    #+#             */
/*   Updated: 2025/03/03 16:21:55 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

                    /*  Cosntrutores */
Fixed::Fixed() : _value(0) {} // Constructor por defecto, inicializa _value a 0

Fixed::Fixed(const int num) // Constructor que convierte un número entero a punto fijo
{
    _value = num << _fractionalBits;
}

Fixed::Fixed(const float num) // Constructor que convierte un número flotante a punto fijo
{
    _value = roundf(num * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &copy) // Constructor de copia que copia el valor de otro objeto Fixed
{
    *this = copy;
}

Fixed& Fixed::operator=(const Fixed &other) // Operador de copia, asigna el valor de otro objeto Fixed
{
    if (this != &other)
        this->_value = other.getRawBits();
    return (*this);
}

                    /*  Destructor */
Fixed::~Fixed() {}// Destructor, se llama cuando el objeto es destruido

                    /* Métodos de acceso modificación y conversion del valor */
int Fixed::getRawBits() const // Retorna el valor crudo del punto fijo (sin conversión)
{
    return (this->_value);
}

void Fixed::setRawBits(int const raw) // Establece el valor crudo del punto fijo
{
    this->_value = raw;
}

float Fixed::toFloat() const // Convierte el valor de punto fijo a flotante
{
    return (float)_value / (1 << _fractionalBits);
}

int Fixed::toInt() const // Convierte el valor de punto fijo a entero
{
    return _value >> _fractionalBits;
}


                    /* Operadores de comparación */
         /* Sobrecarga del operador compara dos valores de punto fijo */
bool Fixed::operator>(const Fixed &other) const // '>'
{
    return (this->_value > other._value);
}

bool Fixed::operator<(const Fixed &other) const // '<'
{
    return (this->_value < other._value);
}

bool Fixed::operator>=(const Fixed &other) const // '>='
{
    return (this->_value >= other._value);
}

bool Fixed::operator<=(const Fixed &other) const // '<='
{
    return (this->_value <= other._value);
}

bool Fixed::operator==(const Fixed &other) const // '=='
{
    return (this->_value == other._value);
}

bool Fixed::operator!=(const Fixed &other) const // '!='
{
    return (this->_value != other._value);
}

                    /* Operadores aritmetricos */
         /* Sobrecarga del operador para operar entre dos valores */
Fixed Fixed::operator+(const Fixed &other) const // '+'
{
    Fixed result;
    result.setRawBits(this->_value + other._value);
    return (result);
}

Fixed Fixed::operator-(const Fixed &other) const // '-'
{
    Fixed result;
    result.setRawBits(this->_value - other._value);
    return (result);
}

Fixed Fixed::operator*(const Fixed &other) const // '*'
{
    Fixed result;
    result.setRawBits((this->_value * other._value) >> _fractionalBits);
    return (result);
}

Fixed Fixed::operator/(const Fixed &other) const // '/'
{
    Fixed result;
    result.setRawBits((this->_value << _fractionalBits) / other._value);
    return (result);
}

                    /* Operadores de incremento y decremento */
Fixed& Fixed::operator++() //++var
{
    this->_value += 1;
    return (*this);
}

Fixed Fixed::operator++(int) //var++
{
    Fixed temp = *this;
    this->_value += 1;
    return (temp);
}

Fixed& Fixed::operator--() //--var
{
    this->_value -= 1;
    return (*this);
}


Fixed Fixed::operator--(int) //var--
{
    Fixed temp = *this;
    this->_value -= 1;
    return (temp);
}


        /* Compararán dos objetos de y devolverán una referencia al objeto, respectivamente */
Fixed& Fixed::min(Fixed& a, Fixed& b) // no cosnt
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) // const
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) // no const
{
    return (a > b) ? a : b; 
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) // cosnt
{
    return (a > b) ? a : b;
}

            /* Sobrecarga del operador de inserción para impresión */
std::ostream& operator<<(std::ostream &out, const Fixed &fixed) 
{
    out << fixed.toFloat();
    return out;
}