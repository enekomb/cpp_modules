/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:51:17 by emunoz            #+#    #+#             */
/*   Updated: 2025/02/28 17:17:22 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


int main(int argc, char **argv)
{
    try
    {
        if (argc < 2)
        {
            std::cerr << "Error: provide a positive integer sequence" << std::endl;
            return (1);
        }
        PmergeMe sorter(argc - 1, argv + 1);
        sorter.sort();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
