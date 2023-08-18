#include "Array.hpp"

int main()
{
    srand(time(NULL));
    Array<int> arr(4);

    for (int i = 0; i < (int)arr.size(); i++)
        arr[i] = rand() % 20;
    for (int i = 0; i < (int)arr.size(); i++)
        std::cout << arr[i] << std::endl;

    Array<std::string> strs(6);

    strs[0] = "hello";
    strs[1] = "guys";
    strs[2] = "how";
    strs[3] = "are";
    strs[4] = "you";
    strs[5] = "today";

    for (int i = 0; i < (int)strs.size(); i++)
        std::cout << strs[i] << std::endl;
}