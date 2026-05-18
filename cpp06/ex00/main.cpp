/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:19:31 by eneko             #+#    #+#             */
/*   Updated: 2025/09/10 13:45:01 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int  main(int argc, char **argv)
{
	if (argc != 2)
		return ((std::cerr << "Usage: " << argv[0] << " <value_to_convert>" << std::endl), 1);
	else
	{
		std::string input = argv[1];
		std::cout << "Converting: " << input << std::endl;
		std::cout << "------------------------" << std::endl;
		ScalarConverter::convert(input);	
	}
	return (0);
}
