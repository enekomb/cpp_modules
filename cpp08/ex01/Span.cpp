/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:02:15 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/10 16:36:00 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void) : _n(0) {}

Span::Span(unsigned int n) : _n(n) {}

Span::Span(const Span &copy) : _n(copy._n), _array(copy._array) 
{
    *this = copy;
}

Span&Span::operator=(const Span &other)
{
    if (this != &other) 
    {
        _n = other._n;
        _array = other._array;
    }
    return (*this);
}

Span::~Span(void) {}


void Span::addNumber(unsigned int num) 
{
    if (_array.size() >= _n)
        throw std::overflow_error("Span is full");
    _array.insert(num);
}

unsigned int Span::shortestSpan() const 
{
    if (_array.size() < 2)
        throw std::logic_error("Not enough elements");
    unsigned int minSpan = UINT_MAX;
    std::set<unsigned int>::const_iterator it1 = _array.begin();
    std::set<unsigned int>::const_iterator it2 = it1;
    ++it2;
    for (; it2 != _array.end(); ++it1, ++it2) 
    {
        unsigned int diff = *it2 - *it1;
        if (diff < minSpan)
            minSpan = diff;
    }
    return (minSpan);
}

unsigned int Span::longestSpan() const 
{
    if (_array.size() < 2)
        throw std::logic_error("Not enough elements");
    return (*_array.rbegin() - *_array.begin());
}

void Span::fillRandom() 
{
    std::srand(std::time(NULL));
    while (_array.size() < _n)
        addNumber(std::rand());
}
