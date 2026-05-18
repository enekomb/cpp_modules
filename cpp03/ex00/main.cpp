/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:25:37 by emunoz            #+#    #+#             */
/*   Updated: 2024/09/23 15:27:24 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap eneko = ClapTrap("Eneko");
    eneko.attack("Juan");
    eneko.beRepaired(5);
    eneko.beRepaired(5);
    eneko.beRepaired(5);
}