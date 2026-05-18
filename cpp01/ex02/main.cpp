/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneko <eneko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 22:30:24 by eneko             #+#    #+#             */
/*   Updated: 2024/09/14 22:38:51 by eneko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <string>

int main()
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringREF = string;

    std::cout << "Memory address of the string variable:\t" << &string << std::endl;
	std::cout << "Memory address held by stringPTR:\t" << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF:\t" << &stringREF << std::endl;
	std::cout << "Value of the string variable:\t\t" << string << std::endl;
	std::cout << "Value pointed to by stringPTR:\t\t" << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF:\t\t" << stringREF << std::endl;
	return (0);
}