/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:19:29 by eneko             #+#    #+#             */
/*   Updated: 2025/09/02 13:31:47 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "AForm.hpp"
# include <stdexcept>

class AForm;

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

        bool		signForm(AForm &form);
        void		executeForm(AForm const &form);


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

    class UnsignedFormException : public std::exception
    
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Form is unsigned");
				}
		};

    private:
        const std::string   _name;
        int                 _grade;
};

std::ostream &operator<<(std::ostream & o, const Bureaucrat & inst);

#endif