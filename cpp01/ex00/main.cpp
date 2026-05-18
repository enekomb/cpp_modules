/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:03:14 by eneko             #+#    #+#             */
/*   Updated: 2024/09/23 13:04:17 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) 
{

    Zombie::randomChump("StackZombie");
    Zombie* heapZombie = Zombie::newZombie("HeapZombie");

    heapZombie->announce();
    delete heapZombie;
    return (0);
}