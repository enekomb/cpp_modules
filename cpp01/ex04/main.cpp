/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eneko <eneko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 12:28:24 by eneko             #+#    #+#             */
/*   Updated: 2024/09/15 22:10:43 by eneko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

void    ft_replace(std::string& content, std::string& s1, std::string& s2)
{
    std::string::size_type pos = 0;
    while ((pos = content.find(s1, pos)) != std::string::npos)
    {
        content.erase(pos, s1.length());
        content.insert(pos, s2);
        pos += s2.length();
    }
}

int main(int argc, char **argv)
{
    if (argc != 4)
	    return (std::cerr << "Too few arguments" << std::endl, 1);
    std::ifstream   fd;
    fd.open(argv[1]);
    if (!fd)
        return (std::cerr << "Not valid file" << std::endl, 1);

    std::string const file = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    std::string content;
    std::string line;
    while(std::getline(fd, line))
    {
        content += line;
        content += '\n';
    }
    fd.close();
    std::ofstream output((file + ".replace").c_str());
    if (!output)
        return (std::cerr << "Error creating outfile" << std::endl, 1);
    if (!s1.empty())
        ft_replace(content, s1, s2);
    output << content;
    output.close();
    return (0);
}