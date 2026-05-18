/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:36:18 by eneko             #+#    #+#             */
/*   Updated: 2025/03/03 16:17:17 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed 
{
    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed&operator=(const Fixed &other);
        ~Fixed();
        
        Fixed(const int intValue);
        Fixed(const float floatValue);
         
        int     getRawBits() const;
        void    setRawBits(int const raw);
        float   toFloat() const;
        int     toInt() const;
     
    private:
                int                 _value;
                static const int    _fractionalBits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif
