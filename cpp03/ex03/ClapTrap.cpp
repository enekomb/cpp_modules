/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:27:07 by emunoz            #+#    #+#             */
/*   Updated: 2025/03/03 17:33:40 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(""), _hitPoint(10), _energyPoint(10), _attackDamage(0) 
{
    std::cout << "Unkown ClapTrap is created" << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) 
{
    std::cout << name << " ClapTrap is created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << this->_name << " ClapTrap is copied" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other) 
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_attackDamage = other._attackDamage;
        this->_energyPoint = other._energyPoint;
        this->_hitPoint = other._hitPoint;
        this->_name = other._name;
    }
    return (*this);
}

ClapTrap::~ClapTrap() 
{
    std::cout << "ClapTrap " << this->_name << " died" << std::endl;  
}

void    ClapTrap::attack(const std::string &target)
{
    if (this->_energyPoint > 0 && this->_hitPoint > 0)
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
        this->_energyPoint--;
    }
    else
        std::cout << "ClapTrap " << this->_name << " is done" << std::endl;
}
void    ClapTrap::takeDamage(const unsigned int amount)
{
    this->_hitPoint -= amount;
    if (this->_energyPoint >= 0 || this->_hitPoint >= 0)
        std::cout << "ClapTrap " << this->_name << " has been damaged by " << amount << " points!, has " << this->_hitPoint << " hit points left" << std::endl;
    else
        std::cout << "ClapTrap " << this->_name << " is done" << std::endl;
}
void    ClapTrap::beRepaired(const unsigned int amount)
{
    this->_hitPoint += amount;
    if (this->_energyPoint >= 0 || this->_hitPoint >= 0)
    {
        std::cout << "ClapTrap " << this->_name << " has repaired " << amount << " hit points!, has " << this->_energyPoint << " energy points left"<< std::endl;
        this->_energyPoint--;
    }
    else
        std::cout << "ClapTrap " << this->_name << " is done" << std::endl;
}

void ClapTrap::setHitPoints(const unsigned int amount)
{
    this->_hitPoint  += amount;   
}

void ClapTrap::setEnergyPoints(const unsigned int amount)
{
    this->_energyPoint  += amount;
}

void ClapTrap::setAttackDamage(const unsigned int amount)
{
    this->_attackDamage  += amount;
}

std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

int ClapTrap::getHitPoints(void) const
{
    return (this->_hitPoint);
}

int ClapTrap::getEnergyPoints(void) const
{
    return (this->_energyPoint);
}

int ClapTrap::getAttackDamage(void) const
{
    return (this->_attackDamage);
}