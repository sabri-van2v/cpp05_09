#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <algorithm>
#include <ctime>

void    sort(std::list<int> &list, std::list<int> &left, std::list<int> &right);
void    algo_merge(std::list<int> &list);

int main(int argc, char **argv);

#endif