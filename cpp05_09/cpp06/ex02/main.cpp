#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <sys/time.h>
#include <cstdlib>
#include <iostream>
#include <exception>

void identify(Base& p)
{
    try{
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
    }
    catch (std::exception &e){}
    try{
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
    }
    catch (std::exception &e){}
    try{
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
    }
    catch (std::exception &e){}
}

void identify(Base* p)
{
    if ((dynamic_cast<A*>(p)))
        std::cout << "A" << std::endl;
    if ((dynamic_cast<B*>(p)))
        std::cout << "B" << std::endl;
    if ((dynamic_cast<C*>(p)))
        std::cout << "C" << std::endl;
}

Base    *generate(void)
{
    int r = rand() % 3;
    if (r == 0)
        return new A;
    else if (r == 1)
        return new B;
    else
        return new C;
}

int main()
{
    struct timeval current;
    gettimeofday(&current, NULL);
    srand(current.tv_usec);

    Base *base = generate();
    identify(base);
    identify(*base);
    delete base;
}