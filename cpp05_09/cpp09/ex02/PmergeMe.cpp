#include "PmergeMe.hpp"

int jacobsthal(int n)
{
    if (n == 0)
        return (0);
    if (n == 1)
        return (1);
    return (jacobsthal(n - 1) + (2 * jacobsthal(n - 2)));
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

std::list<int>::iterator next(std::list<int>::iterator it, int step)
{
    if (step < 0)
    {
        while (step < 0)
        {
            it--;
            step++;
        }
    }
    else
    {
        while (step > 0)
        {
            it++;
            step--;
        }
    }
    return (it);
}

void swap_range_list(std::list<int> &list, int start1, int end1, int start2, int end2)
{
    std::list<int>::iterator it1 = list.begin();
    std::advance(it1, start1);

    std::list<int>::iterator it2 = list.begin();
    std::advance(it2, start2);

    std::list<int> temp(it2, next(it2, end2 - start2 + 1));
    std::copy(it1, next(it1, end1 - start1 + 1), it2);
    std::copy(temp.begin(), temp.end(), it1);
}

void    dichotomy_list(std::list<int> &part_to_moov, std::list<int> &list, int begin, int end, int pair)
{
    int size = end - begin + 1;
    std::list<int>::iterator begin_it = next(list.begin(), begin);
    if (size < 0 || size <= pair)
        size = 0;
    size_t good_index;
    if ((size / pair) % 2 == 1)
        good_index = begin + ((size - 1) / 2) + (pair / 2);
    else
        good_index = begin + (size / 2) + (pair - 1);
    if (good_index >= list.size())
        good_index = list.size() - 1;
    int number_list = *next(list.begin(), good_index);
    int number_moov = part_to_moov.back();
    if (size != 0)
    {
        if (number_moov <= number_list)
            dichotomy_list(part_to_moov, list, begin, good_index - pair, pair);
        else
            dichotomy_list(part_to_moov, list, good_index + 1, end, pair);
    }
    else
    {
        if (good_index + 1 == list.size() && number_moov > number_list)
            begin_it = list.end();
        else if (number_moov > number_list)
            std::advance(begin_it, pair);
        list.insert(begin_it, part_to_moov.begin(), part_to_moov.end());
    }
}



void    sort_list(std::list<int> &list, int range)
{
    int pair = range / 2;
    std::list<int> little_part;
    int count = 0;

    for (std::list<int>::iterator separator = list.begin(); std::distance(list.begin(), separator) < std::distance(list.begin(), list.end()); separator = next(list.begin(), count * pair))
    {
        count++;
        std::list<int>::iterator end_it = next(separator, pair);
        little_part.insert(little_part.end(), separator, end_it);
        list.erase(separator, end_it);
    }
    int already_put = 0;
    int count_bigger = 0;
    int old_jac_number = 0;
    int new_jac_number = 0;
    std::list<int>::iterator it_little_part = next(little_part.begin(), pair - 1);
    std::list<int>::iterator it_list = next(list.begin(), pair - 1);
    while (it_little_part != little_part.end())
    {
        std::list<int> part_to_moov(next(it_little_part, - (pair - 1)), next(it_little_part, 1));
        dichotomy_list(part_to_moov, list, 0, std::distance(list.begin(), next(it_list, - pair + 1 + (already_put * pair) - (count_bigger * pair))) - 1, pair);
        if (new_jac_number > 0 && part_to_moov.back() == *next(it_list, (already_put * pair) - (count_bigger * pair)))
            count_bigger++;
        already_put++;
        old_jac_number = new_jac_number;
        new_jac_number = jacobsthal_order(0);
        if (new_jac_number > old_jac_number)
            count_bigger = 0;
        while ((size_t)((pair * new_jac_number) - 1) >= little_part.size())
        {
            old_jac_number = new_jac_number;
            new_jac_number = jacobsthal_order(0);
            if (new_jac_number > old_jac_number)
                return ;
        }
        it_little_part = next(little_part.begin(), (pair * new_jac_number) - 1);
        it_list = next(list.begin(), (pair * new_jac_number) - 1);
    }
}

void    algo_merge_list(std::list<int> &list)
{
    static int          range = 1;
    std::list<int>    impair;
    std::list<int>::iterator it = list.begin();
    range *= 2;

    if (list.size() / range < 1)
        return ;

    if (list.size() % range != 0)
    {
        std::advance(it, list.size() - (list.size() % range));
        impair.insert(impair.begin(), it, list.end());
        list.erase(it, list.end());
    }

    int pair = range / 2;
    for (size_t i = pair - 1; i < list.size(); i += range)
        if (*next(list.begin(), i) > *next(list.begin(), i + pair))
            swap_range_list(list, i - pair + 1, i, i + 1, i + pair);

    algo_merge_list(list);
    range /= 2;
    sort_list(list, range);
    jacobsthal_order(1);
    if (impair.size() > 0)
        dichotomy_list(impair, list, 0, std::distance(list.begin(), list.end()) - 1, pair);
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
    size_t good_index;
    if ((size / pair) % 2 == 1)
        good_index = begin + ((size - 1) / 2) + (pair / 2);
    else
        good_index = begin + (size / 2) + (pair - 1);
    if (good_index >= vector.size())
        good_index = vector.size() - 1;
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
        if (good_index + 1 == vector.size() && number_moov > number_vector)
            begin = vector.size();
        else if (number_moov > number_vector)
            begin += pair;
        vector.insert(vector.begin() + begin, part_to_moov.begin(), part_to_moov.end());
    }
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
        if (new_jac_number > 0 && part_to_moov[part_to_moov.size() - 1] == vector[i + (already_put * pair) - (count_bigger * pair)])
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