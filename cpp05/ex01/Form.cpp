/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:53:00 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/02 12:33:17 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Unkown"), _sign(false), _grade(150) {}

Form::Form(const std::string& name, bool sing, const int grade) : _name(name), _sign(sing), _grade(grade) 
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& copy) : _grade(copy._grade)
{
    *this = copy;
}
Form & Form::operator=(Form const& other)
{
	this->_sign = other._sign;
	return (*this);
}

Form::~Form(void) {}

void Form::beSigned(Bureaucrat &param)
{
	if (param.signForm(*this))
	{
		std::cout << "This form has been signed by bureaucrat " << param.getName() << std::endl;
		this->_sign = true;
	}
}
std::string const Form::getName(void) const
{
	return (this->_name);
}

bool Form::getSigStatus(void) const
{
	return (this->_sign);
}
int Form::getSignGrade(void) const
{
	return (this->_grade);
}

std::ostream& operator <<(std::ostream &o, const Form &inst)
{
	o << "Form name: " << inst.getName();
	o << ", Status: " << inst.getSigStatus();
	o << ", Sign grade: " << inst.getSignGrade();	
	return (o);
}