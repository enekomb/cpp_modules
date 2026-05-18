/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:06:25 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/11 11:13:10 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream> 
# include <cstdlib>
# include <cfloat>
# include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange(void);
        BitcoinExchange(BitcoinExchange const &copy);
        ~BitcoinExchange(void);
        BitcoinExchange & operator=(BitcoinExchange const & other);

        void    getExchange(const char *filename);
                
    private:
        static std::string              _trim(const std::string &str);
        void                            _loadHistoricData(void);
        std::map<std::string, double>   _historic;
    
};

#endif