/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:24:36 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/02 13:22:02 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Creation Form", 72, 45),_target("Undefined target") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string & target) : AForm("Robotomy Creation Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & copy) :AForm(copy), _target(copy._target) {}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const& other)
{
    if (this != &other) 
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (!this->getSignStatus()) 
        throw Bureaucrat::UnsignedFormException();
    if (executor.getGrade() > this->getExecuteGrade()) 
        throw Bureaucrat::GradeTooLowException();
    else
    {
        srand(time(0));
        if (rand() % 2 == 0)
            std::cout << this->_target << " has been robotomized successfully!" << std::endl;
        else
            std::cout << "Robotomy on " << this->_target << " failed!" << std::endl;
    }
}