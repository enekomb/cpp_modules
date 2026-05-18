/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneko <eneko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:24:44 by eneko             #+#    #+#             */
/*   Updated: 2024/09/14 21:55:56 by eneko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* Zombie::zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return (NULL);
    Zombie* horde = new Zombie[N];

    for (int i = 0; i < N; i++)
        horde[i] = Zombie(name);
    return (horde);
}