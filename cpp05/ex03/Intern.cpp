/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:53:00 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/05 13:01:27 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern& copy) {*this = copy;}

Intern::~Intern(void) {}

Intern & Intern::operator=(Intern const& other) 
{
    if (&other == this)
        return (*this);
    return (*this);
}

AForm* Intern::createShrubbery(const std::string& target) { return new ShrubberyCreationForm(target); }
AForm* Intern::createRobotomy(const std::string& target) { return new RobotomyRequestForm(target); }
AForm* Intern::createPresidential(const std::string& target) { return new PresidentialPardonForm(target); }


AForm* Intern::makeForm(const std::string& name, const std::string& target) 
{
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    
    AForm* (*creators[3])(const std::string&) = {createShrubbery, createRobotomy, createPresidential};

    for (int i = 0; i < 3; i++) 
    {
        if (name == formNames[i]) {
            std::cout << "Intern creates " << name << std::endl;
            return creators[i](target);
        }
    }
    std::cout << "Intern couldn't find form named \"" << name << "\"" << std::endl;
    return (NULL);
}