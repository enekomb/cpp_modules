/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:57:22 by emunoz            #+#    #+#             */
/*   Updated: 2025/02/28 13:57:42 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void iter(T *addr, size_t length, void(*f)(T &))
{
    for (size_t i = 0; i < length; i++)
        f(addr[i]);
}

template <typename T>
void element(T &param)
{
  std::cout << param << " ";   
}
