/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emunoz < emunoz@student.42urduliz.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:51:28 by emunoz            #+#    #+#             */
/*   Updated: 2025/02/28 18:09:26 by emunoz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &copy) { *this = copy; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vector = other._vector;
        _deque  = other._deque;
    }
    return (*this);
}

PmergeMe::PmergeMe(int size, char **args)
{
    for (int i = 0; i < size; ++i)
    {
        std::stringstream ss(args[i]);
        long num;
        ss >> num;
        if (ss.fail() || !ss.eof() || num < 0)
            throw std::runtime_error("Error: invalid input");
        _vector.push_back(static_cast<int>(num));
        _deque.push_back(static_cast<int>(num));
    }
    printSequence(_vector, "Before:");
}

void PmergeMe::sort()
{
    // Vector timing
    clock_t start = clock();
    fordJohnsonVector(_vector);
    clock_t end   = clock();
    double t_vec  = static_cast<double>(end - start) * 1e6 / CLOCKS_PER_SEC;

    // Deque timing
    start = clock();
    fordJohnsonDeque(_deque);
    end   = clock();
    double t_deq  = static_cast<double>(end - start) * 1e6 / CLOCKS_PER_SEC;

    printSequence(_vector, "After:");
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << t_vec << " us" << std::endl;

    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque  : " << t_deq << " us" << std::endl;
}


void PmergeMe::printSequence(const std::vector<int>& v, const std::string& label) const
{
    std::cout << label;
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << " " << v[i];
    std::cout << std::endl;
}

std::vector<int> PmergeMe::jacobsthal(int n)
{
    std::vector<int> j;
    if (n <= 0) 
        return (j);
    j.push_back(0);
    if (n == 1) 
        return (j);
    j.push_back(1);
    while (true)
    {
        int next = j[j.size()-1] + 2 * j[j.size()-2];
        if (next >= n) 
            break;
        j.push_back(next);
    }
    return (j);
}

void PmergeMe::insertionJacobVector(std::vector<int>& v)
{
    int n = v.size();
    if (n <= 1) 
        return;
    std::vector<int> j = jacobsthal(n);
    for (size_t k = 0; k < j.size(); ++k)
    {
        int idx = j[k];
        if (idx >= n) 
            break;
        for (int i = idx; i > 0 && v[i-1] > v[i]; --i)
            std::swap(v[i-1], v[i]);
    }
}

void PmergeMe::insertionJacobDeque(std::deque<int>& d)
{
    int n = d.size();
    if (n <= 1) 
        return;
    std::vector<int> j = jacobsthal(n);
    for (size_t k = 0; k < j.size(); ++k)
    {
        int idx = j[k];
        if (idx >= n)
            break;
        for (int i = idx; i > 0 && d[i-1] > d[i]; --i)
            std::swap(d[i-1], d[i]);
    }
}

// ---------- Ford-Johnson (merge-insert) ----------
void PmergeMe::fordJohnsonVector(std::vector<int>& v)
{
    int n = v.size();
    if (n <= 1) 
        return ;
    if (n == 2) 
    { 
        if (v[0] > v[1]) 
            std::swap(v[0], v[1]); 
        return ; 
    }
    int mid = n/2;
    std::vector<int> left(v.begin(), v.begin()+mid);
    std::vector<int> right(v.begin()+mid, v.end());

    fordJohnsonVector(left);
    fordJohnsonVector(right);
    insertionJacobVector(left);

    // merge
    std::vector<int> merged;
    merged.reserve(n);
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(merged));
    v.swap(merged);
}

void PmergeMe::fordJohnsonDeque(std::deque<int>& d)
{
    int n = d.size();
    if (n <= 1) 
        return ;
    if (n == 2) 
    { 
        if (d[0] > d[1]) 
            std::swap(d[0], d[1]); 
        return ; 
    }
    int mid = n/2;
    std::deque<int> left(d.begin(), d.begin()+mid);
    std::deque<int> right(d.begin()+mid, d.end());

    fordJohnsonDeque(left);
    fordJohnsonDeque(right);
    insertionJacobDeque(left);

    std::deque<int> merged;
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(merged));
    d.swap(merged);
}