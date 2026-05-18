/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Clases.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:40:29 by emunoz            #+#    #+#             */
/*   Updated: 2025/03/03 18:48:45 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CLASES_HPP
# define CLASES_HPP

# include <cstdlib>
# include <iostream>

class Base
{
    public :
        virtual ~Base(void) {};
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base*   generate(void);
void    identify(Base *p);
void    identify(Base &p);

#endif
