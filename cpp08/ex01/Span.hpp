/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:02:24 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/10 16:32:12 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <set>
# include <iostream>
# include <climits>
# include <iterator>
# include <cstdlib>
# include <ctime>

class Span
{
    public:
        Span(void);
        Span(const unsigned int n);
        Span(const Span &copy);
        Span& operator=(const Span &other);
        ~Span(void);

        void            addNumber(unsigned int nbr);
        unsigned int    shortestSpan(void)  const;
        unsigned int    longestSpan(void)   const;

        void            fillRandom(void);
    
    private:
        unsigned  int           _n;
        std::set<unsigned int>  _array;
};

#endif
