/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneko <eneko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:24:54 by eneko             #+#    #+#             */
/*   Updated: 2024/09/15 10:40:29 by eneko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N = 5;
    std::string name = "Raul";

    Zombie *horde = Zombie::zombieHorde(N, name);

    if (horde == NULL)
        return (std::cerr << "Failed to create zombie horde." << std::endl, 1);

    for (int i = 0; i < N; ++i)
        horde[i].announce();

    delete[] horde;
    return (0);
}