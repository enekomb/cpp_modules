/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:18:27 by emunoz            #+#    #+#             */
/*   Updated: 2025/03/03 17:19:15 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    setHitPoints(100);
    setEnergyPoints(100);
    setAttackDamage(30);
    std::cout << "Unkown FragTrap is created" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(20);
    std::cout << name << " FragTrap is created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	*this = copy;
	std::cout << this->getName() << " FragTrap is copied" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other) 
{
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->getName() << " died" << std::endl;  
}

void    FragTrap::highFivesGuys(void) const
{
    std::cout << "FragTrap " << this->getName() << " requests a positive High Five!" << std::endl;
}