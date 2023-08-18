#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::Serializer(Serializer const &s)
{
    (void)s;
}

Serializer::~Serializer()
{}

Serializer &Serializer::operator=(Serializer const &s)
{
    (void)s;
    return (*this);
}

uintptr_t   Serializer::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data        *Serializer::deserialize(uintptr_t integer)
{
    return (reinterpret_cast<Data *>(integer));
}