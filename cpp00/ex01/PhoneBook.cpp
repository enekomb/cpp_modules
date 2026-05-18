/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:00:13 by eneko             #+#    #+#             */
/*   Updated: 2025/03/04 11:36:39 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : _nextIndex(0), _contactCount(0) {}

PhoneBook::~PhoneBook(void) {}

void    PhoneBook::displayHeader(void)
{
    Contact::displayHeader();
    for (int i = 0; i < _contactCount; i++)
        _contacts[i].displayContact(i);
}

void PhoneBook::addContact(const std::string &firstName, const std::string &lastName, const std::string &nickName, const std::string &phoneNumber, const std::string &darkestSecret)
{
    Contact newContact(firstName, lastName, nickName, phoneNumber, darkestSecret);
    _contacts[_nextIndex] = newContact;
    _nextIndex = (_nextIndex + 1) % 8;
    if (_contactCount < 8)
        _contactCount++;
}

void PhoneBook::searchContact(const int index)
{
    if (index >= 0 && index < _contactCount)
        _contacts[index].displayContact();
}

bool PhoneBook::validIndex(const std::string &index)
{
    if (index.length() != 1)
        return (false);
    if (!std::isdigit(index[0]))
        return (false);
    int i = index[0] - '0'; 
    if (i < 0 || i >= _contactCount)
        return (false);
    return (true);
}

bool PhoneBook::empty(void)
{
    if (_contactCount > 0)
        return (false);
    return (true);
}
