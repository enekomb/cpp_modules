/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:09:34 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/10 15:03:39 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Array.hpp"

template <typename T> 
Array<T>::Array(void) : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]()), _size(n) {}

template <typename T>
Array<T>::Array(const Array<T> &copy)
{
    _size = copy._size;
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; i++)
        _array[i] = copy._array[i]; 
}

template <typename T>
Array<T>&Array<T>::operator=(const Array<T> &other)
{
    if (this != &other)
    {
        T* newArray = new T[other._size];
        for (unsigned int i = 0; i < other._size; ++i)
            newArray[i] = other._array[i];
        delete[] _array;
        _array = newArray;
        _size = other._size;
    }
    return *this;
}

template <typename T>
T & Array<T>::operator[](unsigned int i)
{
if (i >= _size)
		throw std::out_of_range("Out");
	return (_array[i]);
}

template <typename T>
const T & Array<T>::operator[](unsigned int i) const
{
    if (i >= _size)
        throw std::out_of_range("Out");
    return _array[i];
}


template <typename T>
Array<T>::~Array(void) 
{
    delete [] _array;
}

template <typename T>
unsigned int Array<T>::size(void) const
{
    return (_size);       
}
