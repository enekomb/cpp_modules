/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 15:41:30 by emunoz            #+#    #+#             */
/*   Updated: 2025/03/03 17:30:52 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
    public:
        DiamondTrap();
        DiamondTrap(const DiamondTrap &copy);
        DiamondTrap&operator=(const DiamondTrap &other);
        ~DiamondTrap();
        
        DiamondTrap(const std::string& name);
        
        void	whoAmI(void) const;
        using 	ScavTrap::attack;

    private:
        std::string _name;
};

#endif
