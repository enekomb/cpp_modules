/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:48:26 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/10 13:52:14 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
    *this = copy;
}

ScalarConverter&ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return (*this);
}

ScalarConverter::~ScalarConverter(void) {}


void ScalarConverter::convert(const std::string &convert)
{
    try
    {
        std::cout << "char: " << _CharConverter(convert) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "int: " << _IntConverter(convert) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << "float: " << std::fixed << std::setprecision(1) << _FloatConverter(convert) << "f" << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout  << e.what() << std::endl;
    }
    try
    {
        std::cout << "double: " << std::fixed << std::setprecision(1) << _DoubleConverter(convert) << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout  << e.what() << std::endl;
    }
}

char ScalarConverter::_CharConverter(const std::string &convert)
{
    if (convert.size() == 1 && !std::isdigit(convert[0]))
        return (convert[0]);

    std::string tmp = convert;
    if (!tmp.empty() && tmp.back() == 'f' && tmp.find('.') != std::string::npos)
        tmp.pop_back();

    double value;
    std::istringstream iss(tmp);
    iss >> value;
    
    if (iss.fail() || !iss.eof())
    throw std::invalid_argument("impossible");
    
    int c = static_cast<int>(value);
    
    if (c < -128 || c > 127)
    throw std::invalid_argument("impossible");
    
    if (!std::isprint(c))
        throw std::invalid_argument("Non displayable");

    return static_cast<char>(c);
}


int ScalarConverter::_IntConverter(const std::string &convert)
{
    if (convert.size() == 1 && !std::isdigit(convert[0]))
        return static_cast<int>(convert[0]);

    std::string tmp = convert;
    if (!tmp.empty() && tmp.back() == 'f' && tmp.find('.') != std::string::npos)
        tmp.pop_back();

    double value;
    std::istringstream iss(tmp);
    iss >> value;

    if (iss.fail() || !iss.eof())
        throw std::invalid_argument("impossible");

    if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        throw std::invalid_argument("impossible");

    return static_cast<int>(value); 
}


float ScalarConverter::_FloatConverter(const std::string &convert)
{
    if (convert.size() == 1 && !std::isdigit(convert[0]))
        return static_cast<float>(convert[0]);

    if (convert == "nan" || convert == "nanf")
        return std::numeric_limits<float>::quiet_NaN();
    if (convert == "inf" || convert == "+inf" || convert == "inff" || convert == "+inff")
        return std::numeric_limits<float>::infinity();
    if (convert == "-inf" || convert == "-inff")
        return -std::numeric_limits<float>::infinity();

    std::string tmp = convert;
    if (!tmp.empty() && tmp.back() == 'f' && tmp.find('.') != std::string::npos)
        tmp.pop_back();

    float value;
    std::istringstream iss(tmp);
    iss >> value;

    if (iss.fail() || !iss.eof())
        throw std::invalid_argument("impossible");

    return value;
}


double ScalarConverter::_DoubleConverter(const std::string &convert)
{
    if (convert.size() == 1 && !std::isdigit(convert[0]))
        return static_cast<double>(convert[0]);

    if (convert == "nan" || convert == "nanf")
        return std::numeric_limits<double>::quiet_NaN();
    if (convert == "inf" || convert == "+inf" || convert == "inff" || convert == "+inff")
        return std::numeric_limits<double>::infinity();
    if (convert == "-inf" || convert == "-inff")
        return -std::numeric_limits<double>::infinity();

    std::string tmp = convert;
    if (!tmp.empty() && tmp.back() == 'f' && tmp.find('.') != std::string::npos)
        tmp.pop_back();

    double value;
    std::istringstream iss(tmp);
    iss >> value;

    if (iss.fail() || !iss.eof())
        throw std::invalid_argument("impossible");
    
    return value;
}

