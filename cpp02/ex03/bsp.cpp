/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneko <eneko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:33:45 by eneko             #+#    #+#             */
/*   Updated: 2024/09/16 21:26:30 by eneko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float area(Point const &p1, Point const &p2, Point const &p3) 
{
    float x1 = p1.getX().toFloat();
    float y1 = p1.getY().toFloat();
    float x2 = p2.getX().toFloat();
    float y2 = p2.getY().toFloat();
    float x3 = p3.getX().toFloat();
    float y3 = p3.getY().toFloat();

    float area = (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2.0f;
    return (area >= 0.0f) ? area : -area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) 
{
    Point lim(0, 0);
    float A = area(a, b, c);

    float A1 = area(point, b, c);
    float A2 = area(a, point, c);
    float A3 = area(a, b, point);

    if ((point == a || point == b || point == c) || (A1 == 0.0f || A2 == 0.0f || A3 == 0.0f))
        return (false);
    return (A == A1 + A2 + A3);
}
