/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:51:36 by emunoz            #+#    #+#             */
/*   Updated: 2025/02/28 15:02:20 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <ctime>
# include <sstream>
# include <algorithm>

class PmergeMe
{
    public:
        PmergeMe();
        PmergeMe(int size, char **args);
        PmergeMe(const PmergeMe &copy);
        ~PmergeMe();

        PmergeMe &operator=(const PmergeMe &other);

        void sort();

    private:
        void printSequence(const std::vector<int>& vec,
                           const std::string& label) const;

        // Ford-Johnson for each container
        void fordJohnsonVector(std::vector<int>& v);
        void fordJohnsonDeque(std::deque<int>& d);

        // helpers
        void insertionJacobVector(std::vector<int>& v);
        void insertionJacobDeque(std::deque<int>& d);
        static std::vector<int> jacobsthal(int n);

        std::vector<int> _vector;
        std::deque<int>  _deque;
};

#endif
