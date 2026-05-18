/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 19:19:31 by eneko             #+#    #+#             */
/*   Updated: 2025/09/02 13:34:52 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() 
{
    // Creación de burócratas
    std::cout << "---- Test 1: Creación de Burócratas ----" << std::endl;
    Bureaucrat bob("Bob", 1);
    Bureaucrat alice("Alice", 150);
    Bureaucrat charlie("Charlie", 25);

    // Creación de formularios
    ShrubberyCreationForm shrubberyForm("Home");
    RobotomyRequestForm robotomyForm("Alice");
    PresidentialPardonForm pardonForm("Charlie");

    // Test de firma de formularios
    std::cout << "\n---- Test 3: Firma de Formularios ----" << std::endl;
    bob.signForm(shrubberyForm);  // Bob tiene el grado suficiente para firmar
    alice.signForm(shrubberyForm);  // Alice no puede firmar porque tiene grado muy bajo
    bob.signForm(robotomyForm);  // Bob tiene el grado suficiente para firmar
    bob.signForm(pardonForm);  // Bob no puede firmar el formulario de perdón porque necesita un grado más alto

    // Intento de firmar un formulario ya firmado
    std::cout << "\n---- Test 4: Intento de Firmar un Formulario Ya Firmado ----" << std::endl;
    bob.signForm(shrubberyForm);  // Ya está firmado, debería mostrar un mensaje de error.

    // Ejecución de formularios
    std::cout << "\n---- Test 5: Ejecución de Formularios ----" << std::endl;
    bob.executeForm(shrubberyForm);  // Bob puede ejecutar el formulario de creación de arbustos
    alice.executeForm(shrubberyForm);  // Alice no puede ejecutar porque no tiene el grado suficiente
    bob.executeForm(robotomyForm);  // Bob puede ejecutar el formulario de solicitud de robotomía
    charlie.executeForm(pardonForm);  // Charlie puede ejecutar el formulario de perdón

    // Ejecución de formularios no firmados
    std::cout << "\n---- Test 6: Intento de Ejecución de un Formulario No Firmado ----" << std::endl;
    ShrubberyCreationForm unsignedForm("Garden");
    bob.executeForm(unsignedForm);  // No está firmado, debería fallar

    // Ejecución con grado insuficiente
    std::cout << "\n---- Test 7: Ejecución con Grado Insuficiente ----" << std::endl;
    bob.executeForm(robotomyForm);  // Bob intenta ejecutar robotomy, pero el grado es insuficiente.
    alice.executeForm(robotomyForm);  // Alice intenta ejecutar robotomy, debería fallar por el grado insuficiente.

    // Ejecución exitosa de Robotomy
    std::cout << "\n---- Test 8: Ejecución exitosa de Robotomy ----" << std::endl;
    bob.executeForm(robotomyForm);  // Bob puede ejecutar, si se simula éxito.

    // Intento de ejecución de otro formulario de robotomía sin firma
    std::cout << "\n---- Test 9: Intento de Ejecución de Robotomy sin Firma ----" << std::endl;
    bob.executeForm(robotomyForm);  // Error porque no está firmado

    // Ejecución del formulario presidencial de perdón
    std::cout << "\n---- Test 10: Ejecución del Perdón Presidencial ----" << std::endl;
    charlie.executeForm(pardonForm);  // Charlie debe ejecutar el perdón.

    // Intento de ejecución con grado bajo
    std::cout << "\n---- Test 11: Intento de Ejecución con Grado Bajo ----" << std::endl;
    bob.executeForm(pardonForm);  // Bob tiene un grado insuficiente para ejecutar el formulario de perdón

    return 0;
}


