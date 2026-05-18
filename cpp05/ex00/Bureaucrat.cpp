/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:19:26 by eneko             #+#    #+#             */
/*   Updated: 2025/09/02 13:24:27 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unkown") , _grade(150)
{
    std::cout << _name << " Bureaucrat has been created with " << _grade << " grade points" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
    {
        this->_grade = grade;
        std::cout << _name << " Bureaucrat has been created with " << _grade << " grade points" << std::endl;
    }
}
Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
    *this = copy;
	std::cout << this->_name << " Bureaucrat has been copied with " << this->_grade << " grade points" << std::endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const& other)
{
	this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << this->_name << " Bureaucrat has been destroyed" << std::endl;
}

std::string Bureaucrat::getName(void) const
{
    return (this->_name);   
}

int Bureaucrat::getGrade(void) const
{
    return(this->_grade);    
}

void Bureaucrat::incrementGrade(int i)
{
    if (i > 0)
        i = i * -1;
    if ((this->_grade + i) < 1)
        throw GradeTooHighException();
    else if ((this->_grade + i) > 150)
        throw GradeTooLowException();
    else
        this->_grade+=i;
}

void Bureaucrat::decrementGrade(int i)
{
    if (i < 0)
        i = i * -1;
    if ((this->_grade + i) < 1)
        throw GradeTooHighException();
    else if ((this->_grade + i) > 150)
        throw GradeTooLowException();
    else
        this->_grade-=i;
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const & inst)
{
	o << inst.getName() << ", bureaucrat grade: " << inst.getGrade();
	return (o);
}