#include "iter.hpp"
#include <iostream>

void    print_s(std::string const &str)
{
    std::cout << str << " ";
}

void    print_i(int const &a)
{
    std::cout << a << " ";
}

int main()
{
    int array[5] = {0, 1, 2, 3, 4};

    iter(array, 5, print_i);
    std::cout << std::endl;

    std::string strings[5] = {"hello", "guys", "i", "code", "now"};

    iter(strings, 5, print_s);
    std::cout << std::endl;
}