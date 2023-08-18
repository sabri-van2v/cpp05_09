#include "iter.hpp"
#include <iostream>

void    print_s(std::string &str)
{
    std::cout << str << " ";
}

void    print_i(int &a)
{
    std::cout << a << " ";
}

void    plus(int &a)
{
    a++;
}

void    add(std::string &str)
{
    str = str + " !";
}

int main()
{
    int array[5] = {0, 1, 2, 3, 4};

    iter(array, 5, print_i);
    std::cout << std::endl;
    iter(array, 5, plus);
    iter(array, 5, print_i);
    std::cout << std::endl;

    std::string strings[5] = {"hello", "guys", "i", "code", "now"};

    iter(strings, 5, print_s);
    std::cout << std::endl;
    iter(strings, 5, add);
    iter(strings, 5, print_s);
    std::cout << std::endl;
}