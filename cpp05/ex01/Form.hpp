/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:06:13 by emunoz            #+#    #+#             */
/*   Updated: 2025/03/03 18:45:25 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
    public:
        Form(void);
        Form(const std::string& name, bool sign, const int grade);
        Form(const Form& copy);
        ~Form(void);

        Form& operator=(const Form& other);
        
		bool				getSigStatus(void) const;
		int					getSignGrade(void) const;
        std::string const	getName(void) const;

        void beSigned(Bureaucrat& param);
    
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
        bool                _sign;
        const int           _grade;
};

std::ostream &operator<<(std::ostream & o, const Form & inst);

#endif