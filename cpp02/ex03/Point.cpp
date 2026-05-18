/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:33:05 by eneko             #+#    #+#             */
/*   Updated: 2025/03/03 16:25:44 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float xValue, const float yValue) : _x(xValue), _y(yValue) {}


Point::Point(const Point &copy) : _x(copy._x), _y(copy._y) 
{
    *this = copy;
}

Point& Point::operator=(const Point &other) 
{
    (void)other;
    return (*this);
}

Point::~Point() {}

const Fixed& Point::getX() const
{
    return (_x);
}


const Fixed& Point::getY() const
{
    return (_y);
}


bool Point::operator==(Point const &other) const
{
    return ((this->_x == other._x) && (this->_y == other._y));
}
