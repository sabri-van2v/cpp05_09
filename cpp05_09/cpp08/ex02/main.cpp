#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "top : " << mstack.top() << std::endl << std::endl;
    mstack.pop();
    std::cout << "top : " << mstack.top() << std::endl << std::endl;
    std::cout << "size : " << mstack.size() << std::endl << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);

    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();

    std::cout << std::endl;

    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }

    MutantStack<int> mstackr;

    mstackr.push(6);
    mstackr.push(18);

    std::cout << std::endl << "top : " << mstackr.top() << std::endl << std::endl;
    mstackr.pop();
    std::cout << "top : " << mstackr.top() << std::endl << std::endl;
    std::cout << "size : " << mstackr.size() << std::endl << std::endl;

    mstackr.push(4);
    mstackr.push(6);
    mstackr.push(738);

    mstackr.push(1);

    MutantStack<int>::reverse_iterator msrit = mstackr.rbegin();
    MutantStack<int>::reverse_iterator msrite = mstackr.rend();

    ++msrit;
    --msrit;

    while (msrit != msrite)
    {
        std::cout << *msrit << std::endl;
        ++msrit;
    }

    return 0;
}