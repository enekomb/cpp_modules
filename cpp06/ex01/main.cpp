/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 12:25:30 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/10 14:33:03 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;

    // Get user input
    std::cout << "Enter int: ";
    std::cin >> data.i;
    std::cout << "Enter long: ";
    std::cin >> data.l;
    std::cout << "Enter float: ";
    std::cin >> data.f;
    std::cin.ignore();
    std::cout << "Enter string: ";
    if (!getline(std::cin, data.s))
        return (std::cerr << "Error reading string" << std::endl, 1);

    // Serialize
    uintptr_t raw = Serializer::serialize(&data);

    // Deserialize
    Data* deserialized = Serializer::deserialize(raw);

    // Print results
    std::cout << "\n=== Serialization Test ===" << std::endl;
    std::cout << "Original Data:" << std::endl;
    std::cout << " int: " << data.i << "\n long: " << data.l << "\n float: " << data.f << "\n string: " << data.s << std::endl;

    std::cout << "\nSerialized raw value: " << raw << std::endl;

    std::cout << "\nDeserialized Data:" << std::endl;
    std::cout << " int: " << deserialized->i << "\n long: " << deserialized->l << "\n float: " << deserialized->f << "\n string: " << deserialized->s << std::endl;

    // Confirm pointers match
    std::cout << "\nPointer match? " << (deserialized == &data ? "Yes" : "No") << std::endl;

    return 0;
}
