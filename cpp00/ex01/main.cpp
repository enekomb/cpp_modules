/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:44:37 by eneko             #+#    #+#             */
/*   Updated: 2025/03/04 11:23:44 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

bool onlySpaces(const std::string &str)
{
    if (str.empty())
        return (true);
    for (std::string::size_type i = 0; i < str.length(); ++i)
    {
        if (!isspace(str[i]))
            return (false);
    }
    return (true);
}

bool validname(const std::string &name)
{
    if (onlySpaces(name))
        return (false);
    for (std::string::size_type i = 0; i < name.length(); ++i)
    {
        if (!std::isalpha(name[i]))
            return (false);
    }
    return (true);
}

bool validNumber(const std::string &number)
{
    if (onlySpaces(number) || number.size() != 9)
        return (false);
    for (std::string::size_type i = 0; i < number.length(); ++i)
    {
        if (!std::isdigit(number[i]))
            return (false);
    }
    return (true);
}


int main(void)
{
    PhoneBook phoneBook;
    std::string key;
    while (key != "EXIT" && key != "exit")
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, key))
			return (std::cout << std::endl, 0);
        else if (key == "ADD" || key == "add")
        {
            std::string firstName, lastName, nickName, phoneNumber, darkestSecret;
            while (true)
            {
                std::cout << "Enter first name: ";
                if (!std::getline(std::cin, firstName))
                    return (std::cout << std::endl, 0);
                if (validname(firstName))
                    break ;
                else
                    std::cout << "Invalid first name. Try again." << std::endl;
            }
            while (true)
            {
                std::cout << "Enter last name: ";
                if (!std::getline(std::cin, lastName))
                    return (std::cout << std::endl, 0);
                if (validname(lastName))
                    break ;
                else
                    std::cout << "Invalid last name. Try again." << std::endl;   
            }
            while (true)
            {
                std::cout << "Enter nickname: ";
                if (!std::getline(std::cin, nickName))
                     return (std::cout << std::endl, 0);
                if (!onlySpaces(nickName))
                    break ;
                else
                    std::cout << "Invalid nickname Try again." << std::endl;
            }
            while (true)
            {
                std::cout << "Enter phone number: ";
                if (!std::getline(std::cin, phoneNumber))
                     return (std::cout << std::endl, 0);
                if (validNumber(phoneNumber))
                    break ;
                else
                    std::cout << "Invalid phone number Try again." << std::endl;
            }
            while (true)
            {
                std::cout << "Enter darkest secret: ";
                if (!std::getline(std::cin, darkestSecret))
                     return (std::cout << std::endl, 0);
                if (!onlySpaces(darkestSecret))
                    break ;
                else
                    std::cout << "Invalid darkest secret Try again." << std::endl;
            }
            phoneBook.addContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
        }
        else if (key == "SEARCH" || key == "search")
        {

            phoneBook.displayHeader();
            if (phoneBook.empty())
            {
                std::cout << "There is no contact to display." << std::endl;
                continue ;
            }
            std::string index;
            while (true)
            {
                std::cout << "Enter the index of the contact to display: ";
                if (!std::getline(std::cin, index))
                     return (std::cout << std::endl, 0);
                if (phoneBook.validIndex(index) && !index.empty())
                {
                    int i = index[0] - '0';
                    phoneBook.searchContact(i);
                    break ;
                }
                else
                {
                    std::cout << "Invalid index" << std::endl;
                    break ;
                }
            }
        }
    }
}
