/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 13:27:10 by emunoz            #+#    #+#             */
/*   Updated: 2025/03/03 16:32:55 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
    public:
        ClapTrap();
        ClapTrap(const ClapTrap &copy);
        ClapTrap&operator=(const ClapTrap &other);
        ~ClapTrap();
        
        ClapTrap(const std::string &name);
        
        void    attack(const std::string &target);
        void    takeDamage(const unsigned int amount);
        void    beRepaired(const unsigned int amount);    

    private:
        std::string _name;
        int         _hitPoint;
        int         _energyPoint;
        int         _attackDamage;
};

#endif