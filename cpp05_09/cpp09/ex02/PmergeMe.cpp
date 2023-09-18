#include "PmergeMe.hpp"

void    insert_elem_list(std::list<int> &big, int elem)
{
    for (std::list<int>::iterator it_big = big.begin(); it_big != big.end(); it_big++)
        if (elem < *it_big)
        {
            big.insert(it_big, elem);
            return  ;
        }
    big.push_back(elem);
}

void    sort_list(std::list<int> &big, std::list<int> &little)
{
    std::list<int>::iterator    it_little = little.begin();

    while (it_little != little.end())
    {
        insert_elem_list(big, *it_little);
        it_little++;
    }
}

void    algo_merge_list(std::list<int> &list)
{
    if (list.size() < 2)
        return ;

    std::list<int>              little;
    std::list<int>              big;
    int                         impair = -1;

    if (list.size() % 2 == 1)
    {
        impair = *(--(list.end()));
        list.pop_back();
    }
    for (std::list<int>::iterator it = list.begin(); it != list.end(); std::advance(it, 2))
    {
        std::list<int>::iterator it_next = ++it;
        it--;
        big.push_back(std::max(*it, *it_next));
        little.push_back(std::min(*it, *it_next));
    }
    algo_merge_list(big);

    sort_list(big, little);
    if (impair != -1)
        insert_elem_list(big, impair);

    list = big;
}

void    insert_elem_vector(std::vector<int> &big, int elem)
{
    for (size_t i = 0; i < big.size(); i++)
        if (elem < big[i])
        {
            big.insert(big.begin() + i, elem);
            return ;
        }
    big.push_back(elem);
}

void    sort_vector(std::vector<int> &big, std::vector<int> &little)
{
    for (size_t i = 0; i < little.size(); i++)
        insert_elem_vector(big, little[i]);
}

void    algo_merge_vector(std::vector<int> &vector)
{
    if (vector.size() < 2)
        return ;

    std::vector<int>    little;
    std::vector<int>    big;
    int                 impair = -1;

    if (vector.size() % 2 == 1)
    {
        impair = vector[vector.size() - 1];
        vector.pop_back();
    }

    for (size_t i = 0; i < vector.size(); i += 2)
    {
        big.push_back(std::max(vector[i], vector[i + 1]));
        little.push_back(std::min(vector[i], vector[i + 1]));
    }
    algo_merge_vector(big);

    sort_vector(big, little);
    if (impair != -1)
        insert_elem_vector(big, impair);

    vector = big;
}