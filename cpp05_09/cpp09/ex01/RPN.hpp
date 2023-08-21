#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <cstdlib>
#include <stack>

int     plus(int a, int b);
int     minus(int a, int b);
int     divided_by(int a, int b);
int     times(int a, int b);
void    calcul(char c, std::string charset, int (*f[4])(int, int), std::stack<int> &rpn);

void    check_input(int argc, char **argv, std::string charset);
void    run_calcul(std::string str, int (*f[4])(int, int), std::stack<int> &rpn);
int     main(int argc, char **argv);

#endif