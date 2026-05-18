/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:41:16 by emunoz            #+#    #+#             */
/*   Updated: 2025/03/03 17:33:04 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// Constructor por defecto
DiamondTrap::DiamondTrap() : ClapTrap("Unnamed_clap_name"), ScavTrap(), FragTrap()
{
    _name = "Unnamed";
    _hitPoint = FragTrap::_hitPoint;
    _energyPoint = ScavTrap::_energyPoint;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << _name << " created" << std::endl;
}

// Constructor con parámetro
DiamondTrap::DiamondTrap(const std::string &name) : ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap()
{
    _name = name;
    _hitPoint = FragTrap::_hitPoint;
    _energyPoint = ScavTrap::_energyPoint;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "DiamondTrap " << _name << " created" << std::endl;
}

// Constructor copia
DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
    *this = copy;
    std::cout << "DiamondTrap " << _name << " copied" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &other) 
{
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

// Destructor
DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << _name << " destroyed" << std::endl;
}

// Función especial whoAmI
void DiamondTrap::whoAmI() const
{
    std::cout << "My DiamondTrap name is: " << _name << std::endl;
    std::cout << "My ClapTrap name is: " << ClapTrap::_name << std::endl;
}
