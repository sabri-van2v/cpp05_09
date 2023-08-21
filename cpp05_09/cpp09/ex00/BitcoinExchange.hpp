#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>

class   ErrorArg : public std::exception
{
    const char *what() const throw()
    {
        return ("could not open file.");
    }
};

class   ErrorSign : public std::exception
{
    const char *what() const throw()
    {
        return ("not a positive number.");
    }
};

class   ErrorTooLarge : public std::exception
{
    const char *what() const throw()
    {
        return ("too large a number.");
    }
};

class   ErrorBadInput : public std::exception
{
public:

    ErrorBadInput(const char* message) : errorMessage(message) {}
    ~ErrorBadInput() throw() {}
    const char* what() const throw()
    {
        return errorMessage.c_str();
    }

private:
    std::string errorMessage;
};

bool                            check_number(std::string &str, char period);
void                            check_date(std::string str);
void                            check_value(std::string str);
void                            bitcoin_value(std::map<std::string, float> &bitcoin, char *filename);

void                            parsing_arg(int argc, char **argv, const char *csvname);
std::map<std::string, float>    parsing_csv(std::string filename);
int                             main(int argc, char **argv);

#endif