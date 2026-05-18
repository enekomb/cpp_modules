/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:19:31 by eneko             #+#    #+#             */
/*   Updated: 2025/09/02 12:34:08 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int  main()
{
	try
	{
		Bureaucrat jose("Joserra", 1); //bureaucrat instanciated
		std::cout << jose << std::endl;
		Form	x1("X1", false, 2);  //form instanciated
		std::cout << x1 << std::endl;

		std::cout << jose << std::endl;

		x1.beSigned(jose);
		std::cout << x1 << std::endl;
		x1.beSigned(jose);
		Form	x2("X2", 1, 1);
		x2.beSigned(jose);		

	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "++++++++++" << std::endl << std::endl;

	try
	{
		Bureaucrat	terelu;
		std::cout << terelu << std::endl;
		Bureaucrat	yeni("tere", 2);
		terelu = yeni;
		std::cout << terelu << std::endl;
		Form	npi;
		std::cout << npi << std::endl;
		Form	x450("X450", true, 50);
		std::cout << x450 << std::endl;
		Form	r120(x450);
		std::cout << r120 << std::endl;
		r120.beSigned(terelu);
		x450.beSigned(yeni);

	}
	catch(std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << std::endl << "++++++++++" << std::endl << std::endl;
	std::cout << "The End" << std::endl;
	
	return (0);
}