/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:06:13 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/05 13:02:42 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    public:
        AForm(void);
        AForm(const std::string& name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm& copy);
        virtual ~AForm(void);

        AForm& operator=(const AForm& other);
        
        std::string const	getName(void) const;
		bool				getSignStatus(void) const;
		int					getSignGrade(void) const;
        int					getExecuteGrade(void) const;

        void beSigned(Bureaucrat& Bureaucrat);

        virtual void execute(const Bureaucrat & execute) const = 0;

    class GradeTooHighException : public std::exception
    {
        public:
            const char* what() const throw() 
            {
                return ("Grade is too high!");
            }
    };

    class GradeTooLowException : public std::exception
    {
        public:
            const char* what() const throw() 
            {
                return ("Grade is too low!");
            }
    };

    private:
        const std::string   _name;
        bool                _isSigned;
        const int           _gradeToSign;
        const int           _gradeToExecute;
};

std::ostream &operator<<(std::ostream & o, const AForm & form);

#endif