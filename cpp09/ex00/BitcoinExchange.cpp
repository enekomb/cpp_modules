/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:06:23 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/11 11:13:27 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) { _loadHistoricData(); }

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _historic(copy._historic) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) 
{
    if (this != &other) 
        _historic = other._historic;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(void) {}


std::string BitcoinExchange::_trim(const std::string &str) 
{
    const char *ws = " \t";
    size_t b = str.find_first_not_of(ws);
    size_t e = str.find_last_not_of(ws);
    return (b == std::string::npos) ? "" : str.substr(b, e - b + 1);
}

void BitcoinExchange::_loadHistoricData() 
{
    std::ifstream file("data.csv");
    if (!file.is_open()) 
    {
        std::cerr << "Error: cannot open data.csv\n";
        return ;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) 
    {
        std::stringstream ss(line);
        std::string date; double rate;
        if (std::getline(ss, date, ',') && (ss >> rate))
            _historic[_trim(date)] = rate;
    }
}

void BitcoinExchange::getExchange(const char *filename) 
{
    std::ifstream file(filename);
    if (!file.is_open()) 
    {
        std::cerr << "Error: cannot open " << filename << '\n';
        return ;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) 
    {
        std::stringstream ss(line);
        std::string date, value_str;
        if (!std::getline(ss, date, '|') || !(ss >> value_str)) 
        {
            std::cerr << "Error: bad input => " << line << '\n';
            continue;
        }
        date = _trim(date);
        value_str = _trim(value_str);

        if (date.size() != 10 || date[4] != '-' || date[7] != '-') 
        {
            std::cerr << "Error: bad input => " << line << '\n';
            continue;
        }

        double value;
        if (!(std::istringstream(value_str) >> value)) 
        {
            std::cerr << "Error: bad input => " << line << '\n';
            continue;
        }
        if (value <= 0)  { std::cerr << "Error: not a positive number.\n"; continue; }
        if (value > 1000){ std::cerr << "Error: too large a number.\n";   continue; }

        std::map<std::string, double>::iterator it = _historic.lower_bound(date);
        if (it == _historic.end() || it->first != date) 
        {
            if (it == _historic.begin()) 
            {
                std::cerr << "Error: bad input => " << date << '\n';
                continue;
            }
            --it;
        }
        std::cout << date << " => " << value << " = " << value * it->second << '\n';
    }
}