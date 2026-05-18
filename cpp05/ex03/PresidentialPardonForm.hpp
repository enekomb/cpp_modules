/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 13:24:33 by emunoz            #+#    #+#             */
/*   Updated: 2025/02/17 17:42:26 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(PresidentialPardonForm const & copy);
	    ~PresidentialPardonForm(void);

        PresidentialPardonForm & operator=(PresidentialPardonForm const & other);

        void    execute(Bureaucrat const &executor) const;

    private:
        std::string _target;
    
};

#endif