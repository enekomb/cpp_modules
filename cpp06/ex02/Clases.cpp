/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Clases.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:00:32 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/10 14:44:50 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Clases.hpp"

Base *generate(void)
{
    srand(time(NULL));
	int s = rand() % 3;
    switch (s)
    {
        case 0:
            std::cout << "Random class A" << std::endl;
            return (new A());
        case 1:
            std::cout << "Random class B" << std::endl;
            return (new B());
        case 2:
            std::cout << "Random class C" << std::endl;
            return (new C());
    }
    return (0);
}

void identify(Base *p)
{
    if (dynamic_cast<A*>(p))
       std::cout << "I am class A" << std::endl;
    else if (dynamic_cast<B*>(p))
       std::cout << "I am class B" << std::endl;
    else if (dynamic_cast<C*>(p))
       std::cout << "I am class C" << std::endl;
    else
       std::cout << "Unknown type class" << std::endl;
}

void identify(Base& p)
{
    try 
    {
        A& a = dynamic_cast<A&>(p);
        std::cout << "I am class A" << std::endl;
        (void)a;
        return ;
    } 
    catch (const std::exception &e) {}

    try 
    {
        B& b = dynamic_cast<B&>(p);
        std::cout << "I am class B" << std::endl;
        (void)b;
        return ;
    } 
    catch (const std::exception &e) {}

    try 
    {
        C& c = dynamic_cast<C&>(p); 
        std::cout << "I am class C" << std::endl;
        (void)c;
        return;
    } 
    catch (const std::exception &e) {}
        std::cout << "Unknown type class" << std::endl;
}
