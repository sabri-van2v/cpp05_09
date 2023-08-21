#include "PmergeMe.hpp"

long    gettime_ns()
{
    struct timespec ts;

    clock_gettime(CLOCK_MONOTONIC, &ts);
    long time_in_nanosec = static_cast<long>(ts.tv_sec) * 1000000000 + ts.tv_nsec;

    return (time_in_nanosec);
}

int main(int argc, char **argv)
{
    (void)argc;(void)argv;
    //check_args(argc, argv);
    int values[] = { 3 , 5 , 9 , 7, 4};
    std::list<int>  lst(values, values + sizeof(values) / sizeof(int));

    for (std::list<int>::iterator  it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << std::endl;
    
    std::cout << std::endl;

    long t1 = gettime_ns();
    algo_merge(lst);
    long t2 = gettime_ns();
    std::cout << "time : " << t2 - t1 << " nsec" << std::endl;

    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
        std::cout << *it << std::endl;
}