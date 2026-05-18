/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:01:58 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/11 12:41:15 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
    try
    {
        std::cout << "=== Basic test ===" << std::endl;
        Span sp(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest  span: " << sp.longestSpan()  << std::endl;

        std::cout << "\n=== Overflow test ===" << std::endl;
        try 
        {
            sp.addNumber(42);
        } 
        catch (const std::exception &e) 
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
        std::cout << "\n=== Random large test ===" << std::endl;
        Span big(10000);
        big.fillRandom();
        std::cout << "Shortest span (big): " << big.shortestSpan() << std::endl;
        std::cout << "Longest  span (big): " << big.longestSpan()  << std::endl;
        std::cout << "\n=== Not enough elements test ===" << std::endl;
        Span small(1);
        small.addNumber(42);
        try 
        {
            std::cout << small.shortestSpan() << std::endl;
        } 
        catch (const std::exception &e) 
        {
            std::cerr << "Caught exception: " << e.what() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "Unhandled exception: " << e.what() << std::endl;
    }
    return 0;
}

