#include "Array.hpp"

template<typename T>
class Array
{
public:

    Array():_size(0), _array(new T[0]){}
    Array(unsigned int n):_size(n), _array(new T[n]){}
    Array(const Array &a)
    {
        _array = new T[0];
        *this = a;
    }
    ~Array()
    {
        delete []_array;
    }

    Array &operator=(const Array &a)
    {
        if (this != &a)
        {
            _size = a._size;
            delete []_array;
            _array = new T[_size];
            memcpy(_array, a._array, sizeof(T) * _size);
        }
        return (*this);
    }

    T &operator[](unsigned int i) const
    {
        if (i >= _size)
            throw (CannotAccessElem());
        return (_array[i]);
    }

    unsigned int size() const
    {
        return (_size);
    }

    class CannotAccessElem : public std::exception
    {
        const char *what() const throw()
        {
            return ("Cannot access memory");
        }
    };

private:
    unsigned int    _size;
    T               *_array;
};