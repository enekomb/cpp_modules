/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:48:23 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/10 13:34:52 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <limits>
# include <sstream>

class ScalarConverter
{
    public:
        static void convert(const std::string &convert);
    
    private:
        ScalarConverter(void);
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter& operator=(const ScalarConverter &other);
        ~ScalarConverter(void);

        static char     _CharConverter(const std::string &convert);
        static int      _IntConverter(const std::string &convert);
        static float    _FloatConverter(const std::string &convert);
        static double   _DoubleConverter(const std::string &convert);
};

#endif