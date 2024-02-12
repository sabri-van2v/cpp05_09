#include "MutantStack.hpp"

template<typename T>
class MutantStack : public std::stack<T>
{
public:

    MutantStack():MutantStack<T>::stack(){}
    ~MutantStack(){}
    MutantStack(MutantStack const &m):MutantStack<T>::stack(){
        *this = m;
    }
    MutantStack &operator=(MutantStack const &m){
        MutantStack<T>::stack::operator=(m);
        return (*this);
    }

    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;

    iterator    begin(){ return this->c.begin(); }
    iterator    end(){ return this->c.end(); }

    reverse_iterator    rbegin(){ return this->c.rbegin(); }
    reverse_iterator    rend(){ return this->c.rend(); }
};