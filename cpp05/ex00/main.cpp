/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:19:31 by eneko             #+#    #+#             */
/*   Updated: 2025/09/02 12:18:56 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int  main()
{
	try
	{
		Bureaucrat jose("jose", 1);
		std::cout << jose << std::endl;
		jose.incrementGrade(1);
		std::cout << jose << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "++++++++++" << std::endl << std::endl;

	try
	{
		Bureaucrat terelu;
		std::cout << terelu << std::endl;
		terelu.decrementGrade(10);
		std::cout << terelu << std::endl;
	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << std::endl << "++++++++++" << std::endl << std::endl;
	std::cout << "The End" << std::endl;
	
	return (0);
}