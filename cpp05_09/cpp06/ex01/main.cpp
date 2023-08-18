#include "Serializer.hpp"

int main()
{
    Data d1;

    d1.str = "hello";

    std::cout << "&d1 : " << &d1 << std::endl;
    std::cout << "d1.str : " << d1.str << std::endl << std::endl;

    uintptr_t integer_ptr = Serializer::serialize(&d1);
    std::cout << "integer_ptr : " << integer_ptr << std::endl << std::endl;

    Data *d2 = Serializer::deserialize(integer_ptr);
    std::cout << "d2 : " << d2 << std::endl;
    std::cout << "d2->str : " << d2->str << std::endl;
}