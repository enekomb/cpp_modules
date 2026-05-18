/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:25:37 by emunoz            #+#    #+#             */
/*   Updated: 2025/03/03 17:22:09 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void) 
{
    ScavTrap scav1;
    
    ScavTrap scav2("ClapScav");

    ScavTrap scav3(scav2);

    scav2.attack("targetDummy");

    scav3.attack("anotherDummy");

    return (0);
}
