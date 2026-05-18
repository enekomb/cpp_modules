/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneko <eneko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 22:26:21 by eneko             #+#    #+#             */
/*   Updated: 2024/09/15 23:04:04 by eneko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(){}

Harl::~Harl(){}

void Harl::debug(void) 
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void) 
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void) 
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void) 
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


void Harl::filter(std::string level) 
{
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i = 0;
    while (i < 4) 
    {
        if (levels[i] == level)
            break ;
        i++;
    }
    switch (i)
    {
        case 0: {
                    std::cout << "[ DEBUG ]\n";
                    this->debug();
                    this->info();
                    this->warning();
                    this->error();
                    break;
                }
        case 1: {
                    std::cout << "[ INFO ]\n";
                    this->info();
                    this->warning();
                    this->error();
                    break;
                }
        case 2: {
                    std::cout << "[ WARNING ]\n";
                    this->warning();
                    this->error();
                    break;
                }
        case 3: {
                    std::cout << "[ ERROR ]\n";
                    this->error();
                    break;
                }
        default:{
                    std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
                    break;
                }
    }
}
