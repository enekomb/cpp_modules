/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneko <eneko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 22:11:16 by eneko             #+#    #+#             */
/*   Updated: 2024/09/15 22:57:56 by eneko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cerr << "Usage: ./harlFilter <level>" << std::endl, 1);

    Harl harl;
    std::string level = argv[1];
    harl.filter(level);
    return (0);
}
