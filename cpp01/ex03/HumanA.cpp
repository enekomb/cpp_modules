/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneko <eneko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:52:03 by eneko             #+#    #+#             */
/*   Updated: 2024/09/15 12:27:28 by eneko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon)
{    this->_name = name;
    this->_weapon.getType();
}

HumanA::~HumanA() {}

void    HumanA::attack()
{
    std:: cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
