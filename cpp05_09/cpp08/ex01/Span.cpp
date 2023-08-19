#include "Span.hpp"

Span::Span(unsigned int size):_size(size)
{}

Span::Span():_size(0)
{}

Span::Span(Span const &s):_size(s._size), _arr(s._arr)
{}

Span::~Span()
{}

Span &Span::operator=(Span const &s)
{
    _arr = s._arr;
    _size = s._size;
    return *this;
}


void    Span::addNumber(int number)
{
    if (_arr.size() == _size)
        throw AlreadyFull();
    _arr.push_back(number);
}

void    Span::addNumbers(int add)
{
    if (add + _arr.size() > _size)
        add = _size - _arr.size();
    std::generate_n(std::back_inserter(_arr), add, Random());
}

int     Span::shortestSpan()
{
    if (_arr.size() <= 1)
        throw NotEnoughElements();
    std::vector<int> tmp = _arr;
    std::sort(tmp.begin(), tmp.end());
    std::vector<int> diff(tmp.size());
    std::adjacent_difference(tmp.begin(), tmp.end(), diff.begin());
    return (*std::min_element(diff.begin(), diff.end()));
}

int     Span::longestSpan()
{
    if (_arr.size() <= 1)
        throw NotEnoughElements();
    std::vector<int>::iterator max_element_it = std::max_element(_arr.begin(), _arr.end());
    std::vector<int>::iterator min_element_it = std::min_element(_arr.begin(), _arr.end());

    return (std::abs(*max_element_it - *min_element_it));
}
