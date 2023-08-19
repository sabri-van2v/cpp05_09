#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <numeric>

class Span
{
public:

    Span(unsigned int size);

    Span();
    Span(Span const &s);
    ~Span();
    Span &operator=(Span const &s);

    void    addNumber(int number);
    void    addNumbers(int add);
    int     shortestSpan();
    int     longestSpan();

    class AlreadyFull : public std::exception
    {
        const char  *what() const throw()
        {
            return ("Array already full");
        }
    };

    class NotEnoughElements : public std::exception
    {
        const char  *what() const throw()
        {
            return ("Not enough elements");
        }
    };

    class Random
    {
    public:
        int operator()(){
            return rand();
        }
    };

private:
    unsigned int        _size;
    std::vector<int>    _arr;
};

#endif