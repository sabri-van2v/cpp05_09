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

void    swap_range_vector(std::vector<int> &vector, int start1, int end1, int start2, int end2)
{
    std::vector<int> temp(vector.begin() + start2, vector.begin() + end2 + 1);
    std::copy(vector.begin() + start1, vector.begin() + end1 + 1, vector.begin() + start2);
    std::copy(temp.begin(), temp.end(), vector.begin() + start1);
}

void    dichotomy_vector(std::vector<int> &part_to_moov, std::vector<int> &vector, int begin, int end, int pair)
{
    int size = end - begin + 1;
    if (size < 0 || size <= pair)
        size = 0;
    int good_index;
    if ((size / pair) % 2 == 1)
        good_index = begin + ((size - 1) / 2) + (pair / 2);
    else
        good_index = begin + (size / 2) + (pair - 1);
    int number_moov = part_to_moov[part_to_moov.size() - 1];
    int number_vector = vector[good_index];

    if (size != 0)
    {
        if (number_moov <= number_vector)
            dichotomy_vector(part_to_moov, vector, begin, good_index - pair, pair);
        else
            dichotomy_vector(part_to_moov, vector, good_index + 1, end, pair);
    }
    else
    {
        if (number_moov > number_vector)
            begin += pair;
        vector.insert(vector.begin() + begin, part_to_moov.begin(), part_to_moov.end());
    }
}

void    sort_vector(std::vector<int> &vector, int range)
{
    int pair = range / 2;

    for (size_t i = pair - 1; i < vector.size(); i += range)
    {
        std::vector<int> part_to_moov(vector.begin() + i - (pair - 1), vector.begin() + i + 1);
        vector.erase(vector.begin() + i - (pair - 1), vector.begin() + i + 1);
        dichotomy_vector(part_to_moov, vector, 0, i - (pair - 1) - 1, pair);
    }
}

void    algo_merge_vector(std::vector<int> &vector)
{
    static int          range = 1;
    std::vector<int>    impair;
    range *= 2;

    if (vector.size() / range < 1)
        return ;

    if (vector.size() % range != 0)
    {
        impair.insert(impair.begin(), vector.end() - (vector.size() % range), vector.end());
        vector.erase(vector.end() - (vector.size() % range), vector.end());
    }

    int pair = range / 2;
    for (size_t i = pair - 1; i < vector.size(); i += range)
        if (vector[i] > vector[i + pair])
            swap_range_vector(vector, i - pair + 1, i, i + 1, i + pair);
    algo_merge_vector(vector);
    range /= 2;
    sort_vector(vector, range);
    if (impair.size() > 0)
        dichotomy_vector(impair, vector, 0, vector.size() - 1, pair);
}