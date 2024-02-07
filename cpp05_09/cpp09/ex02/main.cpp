#include "PmergeMe.hpp"

long    gettime_ns()
{
    struct timespec ts;

    clock_gettime(CLOCK_MONOTONIC, &ts);
    long time_in_nanosec = static_cast<long>(ts.tv_sec) * 1000000000 + ts.tv_nsec;

    return (time_in_nanosec);
}

void    error_message()
{
    std::cout << "Error\n";
    exit(0);
}

std::vector<int> parsing(int argc, char **argv)
{
    std::vector<int>    series;
    long                number;

    if (argc < 2)
        error_message();
    for (int i = 1; argv[i]; i++)
        for (int j = 0; argv[i][j]; j++)
            if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
                error_message();
    for (int i = 1; argv[i]; i++)
        if (strlen(argv[i]) > 10)
            error_message();
    for (int i = 1; argv[i]; i++)
    {
        number = std::strtol(argv[i], NULL, 0);
        if (number > INT_MAX)
            error_message();
        series.push_back(number);
    }
    return (series);
}

void    sort_compare(std::vector<int> &series_v, std::list<int> &series_l)
{
    long    t1, t2, diff;

    t1 = gettime_ns();
    algo_merge_vector(series_v);
    t2 = gettime_ns();
    diff = t2 - t1;

    std::cout << "After:  ";
    for (size_t i = 0; i < series_v.size(); i++)
        std::cout << ' ' << series_v[i];
    std::cout << std::endl;

    std::cout << "Time to process a range of " << series_v.size() << " elements with std::vector  :   " << diff << " ns" << std::endl;

    t1 = gettime_ns();
    algo_merge_list(series_l);
    t2 = gettime_ns();
    diff = t2 - t1;

    std::cout << "Time to process a range of " << series_l.size() << " elements with std::list    :   " << diff << " ns" << std::endl;
}

int main(int argc, char **argv)
{
    std::vector<int>    series_v = parsing(argc, argv);
    std::list<int>      series_l(series_v.begin(), series_v.end());

    std::cout << "Before: ";
    for (size_t i = 0; i < series_v.size(); i++)
        std::cout << ' ' << series_v[i];
    std::cout << std::endl;
    sort_compare(series_v, series_l);
}