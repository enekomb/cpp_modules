/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:02:59 by eneko             #+#    #+#             */
/*   Updated: 2024/09/23 13:03:17 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
    public:
        Zombie(std::string name);
        ~Zombie(); 

        void            announce(void);
        static Zombie*  newZombie(std::string name);
        static void     randomChump(std::string name); 

private:
    std::string _name;
};

#endif