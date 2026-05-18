/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:37:54 by emunoz            #+#    #+#             */
/*   Updated: 2025/03/03 17:28:45 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << "Unkown ScavTrap is created" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << name << " ScavTrap is created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << this->getName() << " ScavTrap is copied" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other) 
{
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->getName() << " died" << std::endl;  
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->getEnergyPoints() >= 0 && this->getHitPoints() >= 0)
    {
        std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
        setEnergyPoints(-1);
    }
    else
        std::cout << "ScavTrap " << this->getName() << " is done" << std::endl;
}

void    ScavTrap::guardGate() const
{
    std::cout << "ScavTrap " << this->getName() << " is now in Gatekeeper mode!" << std::endl;
}