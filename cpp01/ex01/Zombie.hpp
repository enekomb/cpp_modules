/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 21:24:46 by eneko             #+#    #+#             */
/*   Updated: 2025/03/03 15:26:12 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
    public:
        Zombie();
        Zombie(std::string name);
        ~Zombie(); 

        void            announce(void);
        static Zombie*  zombieHorde(int N, std::string name);

    private:
        std::string _name;
};

#endif