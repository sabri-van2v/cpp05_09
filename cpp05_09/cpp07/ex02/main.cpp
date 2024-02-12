#include "Array.hpp"

int main()
{
    srand(time(NULL));
    try {
    Array<int> arr(4);
    Array<int> arr0;

    // std::cout << "arr0: " << arr0[0] << std::endl;
    for (int i = 0; i < (int)arr.size(); i++)
        arr[i] = rand() % 20;
    for (int i = 0; i < (int)arr.size(); i++)
        std::cout << arr[i] << std::endl;

    Array<int> const arr2(arr);
    std::cout << "arr2: " << arr2[1] << std::endl;
    arr[1] = 99;
    std::cout << "arr2: " << arr2[1] << std::endl;
    arr0 = arr2;

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
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}