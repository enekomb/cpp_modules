/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:19:31 by eneko             #+#    #+#             */
/*   Updated: 2025/09/05 13:02:00 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        Bureaucrat bob("Bob", 50);
        Bureaucrat jim("Jim", 140);
        Intern intern;

        std::cout << bob << std::endl;
        std::cout << jim << std::endl;

        // Intern creates a form
        AForm* form = intern.makeForm("shrubbery creation", "home");

        if (form) {
            std::cout << *form << std::endl;

            // Jim tries to sign it
            try {
                form->beSigned(jim);
            } catch (std::exception& e) {
                std::cout << jim.getName() << " failed to sign: " << e.what() << std::endl;
            }

            // Bob signs it
            try {
                form->beSigned(bob);
                std::cout << bob.getName() << " signed the form!" << std::endl;
            } catch (std::exception& e) {
                std::cout << bob.getName() << " failed to sign: " << e.what() << std::endl;
            }

            // Bob executes it
            try {
                form->execute(bob);
            } catch (std::exception& e) {
                std::cout << "Execution failed: " << e.what() << std::endl;
            }

           delete form; // cleanup (unless you switched to smart pointers!)
        }

        // Unknown form request
        AForm* badForm = intern.makeForm("unknown form", "nowhere");
        if (!badForm) {
            std::cout << "Intern couldn't create unknown form." << std::endl;
        }

    } catch (std::exception& e) {
        std::cout << "Unhandled exception: " << e.what() << std::endl;
    }
}



