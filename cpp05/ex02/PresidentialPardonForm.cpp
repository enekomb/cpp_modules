/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:24:30 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/02 13:21:35 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Creation Form", 25, 5),_target("Undefined target") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string & target) : AForm("Presidential Creation Form", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & copy) :AForm(copy), _target(copy._target) {}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
    if (this != &other) 
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSignStatus()) 
        throw Bureaucrat::UnsignedFormException();
    if (executor.getGrade() > this->getExecuteGrade()) 
        throw Bureaucrat::GradeTooLowException();
    else
        std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}