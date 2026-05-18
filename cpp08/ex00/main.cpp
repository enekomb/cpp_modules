/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:51:25 by emunoz            #+#    #+#             */
/*   Updated: 2025/02/28 14:04:34 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void) 
{
    try 
    {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);

        std::vector<int>::iterator it = easyfind(vec, 3);
        std::cout << "Encontrado en vector: " << *it << std::endl;

        // Prueba con una lista
        std::list<int> lst;
        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);

        std::list<int>::iterator it_lst = easyfind(lst, 20);
        std::cout << "Encontrado en lista: " << *it_lst << std::endl;

        // Prueba con un set
        std::set<int> s;
        s.insert(100);
        s.insert(200);
        s.insert(300);
        s.insert(400);

        std::set<int>::iterator it_set = easyfind(s, 300);
        std::cout << "Encontrado en set: " << *it_set << std::endl;

        // Caso de error (no encontrado)
        easyfind(vec, 42); // Esto lanzará una excepción
    } 
    catch (const std::exception &e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return (0);
}
