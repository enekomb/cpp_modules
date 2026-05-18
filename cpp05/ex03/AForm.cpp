/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 16:53:00 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/02 13:31:26 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : _name("Unkown"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string& name, const int gradeToSing, const int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSing), _gradeToExecute(gradeToExecute)
{
    if (gradeToSing < 1)
        throw GradeTooHighException();
    else if (gradeToSing > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm& copy) : _name(copy._name), _isSigned(copy._isSigned), _gradeToSign(copy._gradeToSign), _gradeToExecute(copy._gradeToExecute)
{
    *this = copy;
}

AForm::~AForm(void) {}

AForm & AForm::operator=(AForm const& other)
{
    if (this != &other)
        this->_isSigned = other._isSigned;
    return (*this);
}


std::string const AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::getSignStatus(void) const
{
	return (this->_isSigned);
}

int AForm::getSignGrade(void) const
{
	return (this->_gradeToSign);
}

int AForm::getExecuteGrade(void) const
{
	return (this->_gradeToExecute);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_gradeToSign)
        throw GradeTooLowException();
    else
        this->_isSigned = true;
}


std::ostream& operator<<(std::ostream &o, const AForm &form)
{
    o << "Form name: " << form.getName();
    o << ", Status: " << (form.getSignStatus() ? "Signed" : "Unsigned");
    o << ", Sign grade: " << form.getSignGrade();
    o << ", Execution grade: " << form.getExecuteGrade();
    return (o);
}
