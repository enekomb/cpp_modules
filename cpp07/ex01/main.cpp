/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:32:40 by emunoz            #+#    #+#             */
/*   Updated: 2025/02/19 19:05:36 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(int argc, char **argv)
{
    if (argc > 1)
    {
        std::cout << "------------Your---test------------" << std::endl;
        iter((argv + 1), argc - 1, element);
        std::cout << std::endl;
    }
    else
        std::cout << "You can try with your arguments" << std::endl;
    std::cout << "------------Test---int-------------" << std::endl;
    int array[5] = {1, 3, 6 ,8, 0};
    iter(array, 5, element);
    std::cout << std::endl << "------------Test--str--------------" << std::endl;
    std::string str[5] = {"hola", "mundo", "cruel", "adios", "venga"};
    iter(str, 5, element);
    std::cout << std::endl << "------------Test--double-----------" << std::endl;
    double d[5] = {1.1, 3.2, 6.9 ,8.07, 0.550};
    iter(d, 5, element);
    std::cout << std::endl;
    
}