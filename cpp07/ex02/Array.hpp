/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:09:17 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/10 15:03:06 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>

template <typename T> 
class Array
{
    public:
        Array(void);
        Array(unsigned int n);
        Array(const Array &copy);
        Array& operator=(const Array &other);
        T & operator[](unsigned int i);
        const T & operator[](unsigned int i) const;
        ~Array(void);

        unsigned int    size(void) const;
    
    private:
        T               *_array;
        unsigned int    _size;
};

#include "Array.tpp"

#endif
