/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 22:11:37 by eneko             #+#    #+#             */
/*   Updated: 2025/03/03 15:31:36 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl 
{
    public:
        void complain(const std::string &level);

    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
};

#endif