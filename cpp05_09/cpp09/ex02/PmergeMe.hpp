#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
#include <ctime>
#include <cmath>

void    algo_merge_list(std::list<int> &list);
void    algo_merge_vector(std::vector<int> &vector);

long                gettime_ns();
void                error_message();
std::vector<int>    parsing(int argc, char **argv);
void                sort_compare(std::vector<int> &series_v, std::list<int> &series_l);
int                 main(int argc, char **argv);

#endif