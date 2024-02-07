#include "RPN.hpp"

int plus(int a, int b)
{
    return a + b;
}

int minus(int a, int b)
{
    return a - b;
}

int divided_by(int a, int b)
{
    if (b == 0)
    {
        std::cout << "divided by zero" << std::endl;
        throw Error();
    }
    return a / b;
}

int times(int a, int b)
{
    return a * b;
}

void    calcul(char c, std::string charset, int (*f[4])(int, int), std::stack<int> &rpn)
{
    int a, b;

    if (rpn.size() < 2)
    {
        std::cout << "Error" << std::endl;
        throw Error();
    }
    b = rpn.top();
    rpn.pop();
    a = rpn.top();
    rpn.pop();
    rpn.push(f[charset.find(c)](a, b));
}