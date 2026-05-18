/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:45:20 by emunoz            #+#    #+#             */
/*   Updated: 2025/02/28 13:55:32 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

template <typename T>

void swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
template <typename T>

const T& min(T &a, T &b)
{
    if (b <= a)
        return (b);
    return (a);
}
template <typename T>

const T& max(T &a, T &b)
{
    if (b >= a)
        return (b);
    return (a);
}
