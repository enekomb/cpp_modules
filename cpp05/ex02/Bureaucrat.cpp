/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:19:26 by eneko             #+#    #+#             */
/*   Updated: 2025/09/02 13:30:26 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unkown") , _grade(150) {}

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
Bureaucrat::Bureaucrat(const Bureaucrat& copy) : _name(copy._name), _grade(copy._grade) {}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat & Bureaucrat::operator =(Bureaucrat const& other)
{
	this->_grade = other._grade;
	return (*this);
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

bool Bureaucrat::signForm(AForm &param)
{
    try
    {
        if (param.getSignStatus())
        {
            std::cout << this->_name << " couldn't sign " << param.getName() << " because it's already signed." << std::endl;
            return (false);
        }
        else
        {
            param.beSigned(*this);
            std::cout << this->_name << " signed " << param.getName() << std::endl;
            return (true);
        }
    }
    catch (const std::exception &e)
    {
        std::cout << this->_name << " couldn't sign " << param.getName() << " because " << e.what() << std::endl;
        return (false);
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        if (!form.getSignStatus())
            throw UnsignedFormException();
        if (this->_grade > form.getExecuteGrade())
            throw GradeTooLowException();
        else
        {
            form.execute(*this);
            std::cout << this->_name << " executed " << form.getName() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cout << this->_name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}


std::ostream & operator<<(std::ostream & o, Bureaucrat const & inst)
{
	o << inst.getName() << ", bureaucrat grade: " << inst.getGrade();
	return (o);
}