/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:25:37 by emunoz            #+#    #+#             */
/*   Updated: 2025/03/03 17:35:12 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "DiamondTrap.hpp"

int main(void) 
{
    DiamondTrap dt1;
    dt1.whoAmI();

    DiamondTrap dt2("Diamondy");
    dt2.whoAmI();

    DiamondTrap dt3(dt2);
    dt3.whoAmI();

    return (0);
}

