/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:03:08 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/10 14:00:16 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Clases.hpp"

int main() 
{
    int option;
    
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Choose the class to generate:" << std::endl;
    std::cout << "1. Generate class A" << std::endl;
    std::cout << "2. Generate class B" << std::endl;
    std::cout << "3. Generate class C" << std::endl;
    std::cout << "Enter your choice (1, 2, or 3): ";
    std::cin >> option;
    std::cout << "---------------------------------------" << std::endl;
    
    if (option == 1)
    {
        Base* Aobj = new A;
        identify(Aobj);
        delete Aobj;
    }
    else if (option == 2)
    {
        Base* Bobj = new B;
        identify(Bobj);
        delete Bobj;
    }
    else if (option == 3)
    {
        Base* Cobj = new C;
        identify(Cobj);
        delete Cobj;
    }
    else 
        std::cout << "Invalid option selected!" << std::endl;
    
    std::cout << "-----------------Random----------------" << std::endl;
    Base* obj = generate();
    identify(obj);
    delete obj;

    std::cout << "---------------------------------------" << std::endl;
    Base* obj2 = generate();
    identify(*obj2);
    delete obj2;
    return (0);
}