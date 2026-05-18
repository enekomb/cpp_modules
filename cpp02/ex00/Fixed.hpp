/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:36:18 by eneko             #+#    #+#             */
/*   Updated: 2025/03/03 16:27:07 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed 
{
    public:
        Fixed();
        Fixed(const Fixed &other);
        Fixed&operator=(const Fixed &other);
        ~Fixed();
    
        int     getRawBits() const;
        void    setRawBits(int const raw);
    
    private:
        int                 _value;
        static const int    _fractionalBits = 8;
};

#endif
