#include "RPN.hpp"

void    check_input(int argc, char **argv, std::string charset)
{
    if (argc != 2)
    {
        std::cout << "Error" << std::endl;
        throw Error();
    }
    for (int i = 0; argv[1][i]; i++)
        if (charset.find(argv[1][i]) == std::string::npos)
        {
            std::cout << "Error" << std::endl;
            throw Error();
        }
    for (int i = 0; argv[1][i]; i++)
        if (argv[1][i] != ' ' && (argv[1][i + 1] != ' ' && argv[1][i + 1]))
            {
                std::cout << "Error" << std::endl;
                throw Error();
            }
}

void    run_calcul(std::string str, int (*f[4])(int, int), std::stack<int> &rpn)
{
    int i = 0;

    while (i < static_cast<int>(str.size()))
    {
        if (str[i] == ' ')
        {
            i++;
            continue ;
        }
        else if (str[i] >= '0' && str[i] <= '9')
            rpn.push(str[i] - '0');
        else
            calcul(str[i], "+-/*", f, rpn);
        i++;
    }
}

int main(int argc, char **argv)
{
    try{
    check_input(argc, argv, "0123456789+-/* ");
    }
    catch (std::exception &e){
        return (1);
    }

    std::stack<int> rpn;
    int (*f[4])(int, int) = {
        plus, minus, divided_by, times
    };

    try
    {    
        run_calcul(argv[1], f, rpn);

        if (rpn.size() != 1)
        {
            std::cout << "Error" << std::endl;
            throw Error();
        }

        std::cout << rpn.top() << std::endl;
    }
    catch (std::exception &e){
        return (1);
    }
}