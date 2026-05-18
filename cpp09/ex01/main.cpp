/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:40:36 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/11 11:33:45 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) 
    {
        std::cerr << "Usage: " << argv[0] << " \"<RPN expression>\"\n";
        return (1);
    }
    try
    {
        RPN rpn;
        rpn.evaluate(argv[1]);
    } 
    catch (const std::exception &e) 
    {
        std::cerr << "Error: " << e.what() << '\n';
        return (1);
    }
    return (0);
}
