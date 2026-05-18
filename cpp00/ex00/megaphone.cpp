/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:44:26 by eneko             #+#    #+#             */
/*   Updated: 2025/02/26 17:39:24 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc < 2)
       return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);

    for (int j = 1; j < argc; j++)
    {
        int i = 0;
        while (argv[j][i] && isspace(argv[j][i]))
            i++;
        for (; argv[j][i]; i++)
        {
            if ((isspace(argv[j][i]) && isspace(argv[j][i + 1])) || (isspace(argv[j][i]) && argv[j][i + 1] == '\0'))
                continue ;
            std::cout << (char)toupper(argv[j][i]);
        }
        if (j != argc -1)
            std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}
