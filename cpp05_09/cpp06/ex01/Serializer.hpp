#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

typedef struct data{
    std::string str;
} Data;

class Serializer
{
public:

    static uintptr_t   serialize(Data *ptr);
    static Data        *deserialize(uintptr_t integer);

private:
    Serializer();
    Serializer(Serializer const &s);
    ~Serializer();
    Serializer &operator=(Serializer const &s);
};

#endif