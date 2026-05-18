/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:24:41 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/02 13:22:37 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation Form", 145, 137),_target("Undefined target") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target) : AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & copy) :AForm(copy), _target(copy._target) {}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
    if (this != &other) 
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSignStatus()) 
        throw Bureaucrat::UnsignedFormException();
    if (executor.getGrade() > this->getExecuteGrade()) 
        throw Bureaucrat::GradeTooLowException();
    else
    {
        std::ofstream file((this->_target + "_shrubbery").c_str());
        if (!file.is_open())
        {
            std::cerr << "Error: Unable to open file for writing." << std::endl;
            return ;
        }
        file << "      .     .          .\n";
        file << "   .  . .  . .        .\n";
        file << "        .  |     .    .\n";
        file << "       \\|/ |//       .\n";
        file << "    .   \\|///        .\n";
        file << "      \\\\|/ \\\\     .\n";
        file << "      \\\\\\\\|//     .\n";
        file << "         \\|/         .\n";
        file << "         \\|/         .\n";
        file << "          |           .\n";
        file << "          |           .\n";
        file.close();
        std::cout << "Shrubbery created successfully in " << this->_target + "_shrubbery" << std::endl;
    }
}