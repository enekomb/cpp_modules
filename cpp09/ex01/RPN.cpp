/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 11:40:52 by emunoz            #+#    #+#             */
/*   Updated: 2025/09/11 11:35:39 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(const RPN &copy) {*this = copy;}

RPN&RPN::operator=(RPN const &other)
{
    (void)other;
    return *this;
}

RPN::~RPN(void) {}

bool RPN::isOperator(const std::string &tok) 
{
    return tok == "+" || tok == "-" || tok == "*" || tok == "/";
}

double RPN::apply(double a, double b, const std::string &op) 
{
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;
    if (op == "/") 
    {
        if (b == 0) 
            throw std::runtime_error("division by zero");
        return a / b;
    }
    throw std::runtime_error("invalid operator");
}

void RPN::evaluate(const std::string &expr) 
{
    std::istringstream iss(expr);
    std::stack<double> st;
    std::string tok;

    while (iss >> tok) 
    {
        // single-digit number check (per subject numbers < 10)
        if (tok.size() == 1 && std::isdigit(tok[0])) 
        {
            st.push(tok[0] - '0');
        } 
        else if (isOperator(tok)) 
        {
            if (st.size() < 2)
                throw std::runtime_error("insufficient operands");
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            st.push(apply(a, b, tok));
        } 
        else 
        {
            throw std::runtime_error("invalid token: " + tok);
        }
    }
    if (st.size() != 1)
        throw std::runtime_error("invalid RPN expression");
    std::cout << st.top() << std::endl;
}

