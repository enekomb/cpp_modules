/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 19:33:40 by eneko             #+#    #+#             */
/*   Updated: 2025/03/03 16:25:49 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"
# include <iostream>

class Point 
{
    public:
        Point();
        Point(const Point &copy);
        Point& operator=(const Point &other);
        ~Point();
    
        Point(const float x, const float y);
    
        const Fixed& getX() const;
        const Fixed& getY() const;
    
        bool  operator==(const Point &other) const;

    private:
        const Fixed _x;
        const Fixed _y;
};

bool    bsp(Point const a, Point const b, Point const c, Point const point);

#endif
