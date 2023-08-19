#include "easyfind.hpp"

int  main()
{
    std::vector<int> arr_v;
    for (int i = 0; i < 5; i++)
        arr_v.push_back(i);

    std::list<int>   arr_l;
    for (int i = 0; i < 5; i++)
        arr_l.push_back(i + 5);

    std::vector<int>::iterator it_v;
    std::list<int>::iterator it_l;

    it_v = easyfind(arr_v, 3);
    if (it_v != arr_v.end())
        std::cout << *it_v << std::endl;
    else
        std::cout << "value not found\n";

    it_l = easyfind(arr_l, 9);
    if (it_l != arr_l.end())
        std::cout << *it_l << std::endl;
    else
        std::cout << "value not found\n";
}