/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:20:20 by eneko             #+#    #+#             */
/*   Updated: 2025/03/04 11:44:39 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook 
{
    public:
        PhoneBook(void);
        ~PhoneBook(void);
        
    
        void    addContact(const std::string &firstName, const std::string &lastName, const std::string &nickName, const std::string &phoneNumber, const std::string &darkestSecret);
        void    searchContact(const int index);
        void    displayHeader(void);

        bool    validIndex(const std::string &index);
        bool    empty(void);

    private:
        Contact     _contacts[8];
        int         _nextIndex;
        int         _contactCount;
};

#endif
