/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:06:21 by emunoz            #+#    #+#             */
/*   Updated: 2025/02/28 14:24:33 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iterator>
# include <stdexcept> 
# include <vector>
# include <list>
# include <set>
# include <iostream>

template <typename T>
typename T::iterator easyfind(T &container, int n);

#include "easyfind.tpp"

#endif