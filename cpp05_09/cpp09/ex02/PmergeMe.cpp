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

int jacobsthal(int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    return (jacobsthal(n - 1) + (2 * jacobsthal(n - 2)));
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

int     jacobsthal_order(int reset)
{
    static int  current = jacobsthal(3) + 1;
    static int  older = jacobsthal(2);
    static int  jac_terms = 3;

    if (reset)
    {
        current = jacobsthal(3) + 2;
        older = jacobsthal(2);
        jac_terms = 3;
    }

    current--;

    if (current == older)
    {
        current = jacobsthal(jac_terms + 1);
        older = jacobsthal(jac_terms);
        jac_terms++;
    }
    return (current);
}

void    sort_vector(std::vector<int> &vector, int range)
{
    int pair = range / 2;
    std::vector<int> little_part;

    for (size_t separator = 0; separator < vector.size(); separator += pair)
    {
        little_part.insert(little_part.end(), vector.begin() + separator, vector.begin() + separator + pair);
        vector.erase(vector.begin() + separator, vector.begin() + separator + pair);
    }

    int already_put = 0;
    int count_bigger = 0;
    int old_jac_number = 0;
    int new_jac_number = 0;
    size_t  i = pair - 1;

    while (i < vector.size())
    {
        std::vector<int> part_to_moov(little_part.begin() + i - (pair - 1), little_part.begin() + i + 1);
        dichotomy_vector(part_to_moov, vector, 0, i - pair + (already_put * pair) - (count_bigger * pair), pair);
        if (new_jac_number > 0 && part_to_moov[part_to_moov.size() - 1] == vector[i - pair + (already_put * pair)])
            count_bigger++;
        already_put++;
        old_jac_number = new_jac_number;
        new_jac_number = jacobsthal_order(0);
        if (new_jac_number > old_jac_number)
            count_bigger = 0;
        i = (pair * new_jac_number) - 1;
        while (i >= little_part.size())
        {
            old_jac_number = new_jac_number;
            new_jac_number = jacobsthal_order(0);
            if (new_jac_number > old_jac_number)
                return ;
            i = (pair * new_jac_number) - 1;
        }
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
    jacobsthal_order(1);
    if (impair.size() > 0)
        dichotomy_vector(impair, vector, 0, vector.size() - 1, pair);
}