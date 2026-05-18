/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:40:58 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/11 11:32:09 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <fstream>
# include <sstream> 
# include <cstdlib>
# include <cfloat>
# include <stack>

class RPN
{
    public:
        RPN(void);
        RPN(RPN const &copy);
        RPN & operator=(RPN const & other);
        ~RPN(void);

        void evaluate(const std::string &expr);

    private:
        static bool isOperator(const std::string &tok);
        static double apply(double a, double b, const std::string &op);
    
};

#endif