/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneko <eneko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:24:49 by eneko             #+#    #+#             */
/*   Updated: 2024/09/14 21:48:49 by eneko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout  << "Unamed Zombie is created!" << std::endl;
}

Zombie::Zombie(std::string name)
{
        this->_name = name;
        std::cout << _name << " is created!" << std::endl;
}

Zombie::~Zombie() 
{
        std::cout << this->_name << " is destroyed!" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}