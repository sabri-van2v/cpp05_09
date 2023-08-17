#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat a("Mathilde", 150);

    try
    {
        std::cout << a << std::endl;
        a.decrement();
        std::cout << a << std::endl;
        a.increment();
        std::cout << a << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}