/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:19:29 by eneko             #+#    #+#             */
/*   Updated: 2025/09/02 12:24:31 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "Form.hpp"
# include <stdexcept>

class Form;

class Bureaucrat 
{
    public:
        Bureaucrat(void);
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& copy);
        ~Bureaucrat(void);

        Bureaucrat& operator=(const Bureaucrat& other);

        std::string getName(void) const;
        int         getGrade(void) const;

        void        incrementGrade(int i);
        void        decrementGrade(int i);

        bool		signForm(Form &param);

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
        int                 _grade;
};

std::ostream &operator<<(std::ostream & o, const Bureaucrat & inst);

#endif