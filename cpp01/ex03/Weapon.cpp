/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:07:21 by eneko             #+#    #+#             */
/*   Updated: 2025/03/03 15:30:15 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

Weapon::Weapon(const std::string &weapon):_type(weapon) {}

Weapon::~Weapon() {}

const std::string&Weapon::getType()
{
    return (this->_type);
    
}

void Weapon::setType(const std::string &type)
{
    this->_type = type;   
}