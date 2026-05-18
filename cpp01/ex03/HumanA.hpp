/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:52:06 by eneko             #+#    #+#             */
/*   Updated: 2025/03/03 15:27:33 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>
# include <string>

class HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(); 

        void                    attack();

    private:
        std::string _name;
        Weapon      &_weapon;
};

#endif