#include "PmergeMe.hpp"

void    sort(std::list<int> &list, std::list<int> &left, std::list<int> &right)
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

void    algo_merge(std::list<int> &list)
{
    if (list.size() < 2)
        return ;

    std::list<int>              left;
    std::list<int>              right;
    std::list<int>::iterator    it = list.begin();

    std::advance(it, list.size() / 2);
    left.splice(left.begin(), list, list.begin(), it);
    right.splice(right.begin(), list);

    algo_merge(left);
    algo_merge(right);

    sort(list, left, right);
}