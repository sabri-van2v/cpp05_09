#include "PmergeMe.hpp"

void    sort_list(std::list<int> &list, std::list<int> &left, std::list<int> &right)
{
    std::list<int>::iterator    it_right = right.begin();
    std::list<int>::iterator    it_left = left.begin();

    while (it_left != left.end() && it_right != right.end())
    {
        if (*it_left < *it_right)
        {
            list.push_back(*it_left);
            it_left++;
        }
        else
        {
            list.push_back(*it_right);
            it_right++;
        }
    }

    for ( ; it_left != left.end(); it_left++)
        list.push_back(*it_left);
    for ( ; it_right != right.end(); it_right++)
        list.push_back(*it_right);
}

void    algo_merge_list(std::list<int> &list)
{
    if (list.size() < 2)
        return ;

    std::list<int>              left;
    std::list<int>              right;
    std::list<int>::iterator    it = list.begin();

    std::advance(it, list.size() / 2);
    left.splice(left.begin(), list, list.begin(), it);
    right.splice(right.begin(), list);

    algo_merge_list(left);
    algo_merge_list(right);

    sort_list(list, left, right);
}

void    sort_vector(std::vector<int> &vector, std::vector<int> &left, std::vector<int> &right)
{
    size_t  i_right = 0;
    size_t  i_left = 0;
    size_t  i_vec = 0;

    while (i_left != left.size() && i_right != right.size())
    {
        if (left[i_left] < right[i_right])
        {
            vector[i_vec] = left[i_left];
            i_vec++;
            i_left++;
        }
        else
        {
            vector[i_vec] = right[i_right];
            i_vec++;
            i_right++;
        }
    }
    for ( ; i_left != left.size(); i_left++)
        vector[i_vec++] = left[i_left];
    for ( ; i_right != right.size(); i_right++)
        vector[i_vec++] = right[i_right];
}

void    algo_merge_vector(std::vector<int> &vector)
{
    if (vector.size() < 2)
        return ;

    std::vector<int>    left(vector.begin(), vector.begin() + vector.size() / 2);
    std::vector<int>    right(vector.begin() + vector.size() / 2, vector.end());

    algo_merge_vector(left);
    algo_merge_vector(right);

    sort_vector(vector, left, right);
}