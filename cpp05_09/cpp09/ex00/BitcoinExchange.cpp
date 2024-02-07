#include "BitcoinExchange.hpp"

bool    check_number(std::string &str, char period)
{
    if (!(str[0] >= '0' && str[0] <= '9'))
        return (false);
    char *endptr;
    int number = std::strtod(str.c_str(), &endptr);
    if (*endptr != '-' && !(*endptr == ' ' && *(endptr + 1) == '|'  && period == 'd'))
        return (false);
    switch (period)
    {
        case 'y':
            if (number > 2008)
                return (true);
            break;
        case 'm':
            if (number >= 1 && number <= 12)
                return (true);
            break;
        case 'd':
            if (number >= 1 && number <= 31)
                return (true);
            break;
    }
    return (false);
}

void    check_date(std::string str)
{
    if (!check_number(str, 'y'))
        throw ErrorBadInput(str.c_str());
    std::string str_cpy = str.substr(str.find('-') + 1);
    if (!check_number(str_cpy, 'm'))
        throw ErrorBadInput(str.c_str());
    str_cpy = str_cpy.substr(str_cpy.find('-') + 1);
    if (!check_number(str_cpy, 'd'))
        throw ErrorBadInput(str.c_str());
}

void    check_value(std::string str)
{
    if (not (str[0] >= '0' && str[0] <= '9'))
        throw ErrorBadInput(str.c_str());
    float   number;
    char    *endptr;
    number = std::strtof(str.substr(str.find('|') + 1).c_str(), &endptr);
    if (*endptr)
        throw ErrorBadInput(str.c_str());
    if (number < 0)
        throw ErrorSign();
    if (number > 1000)
        throw ErrorTooLarge();
}

bool    good_format(std::string str)
{
    for (size_t i = 0; i < 10; i++)
    {
        if (i == str.size())
            return (false);
        if (i == 4 || i == 7)
        {
            if (str[i] != '-')
                return (false);
        }
        else
        {
            if (!(str[i] >= '0' && str[i] <= '9'))
                return (false);
        }
    }
    for (size_t i = 10; i < 13; i++)
    {
        if (i == str.size())
            return (false);
        if (i == 11)
        {
            if (str[i] != '|')
                return (false);
        }
        else
        {
            if (str[i] != ' ')
                return (false);
        }
    }
    for (size_t i = 13; i < str.size(); i++)
    {
        if (str[i] != '.' && str[i] != '-' && !(str[i] >= '0' && str[i] <= '9'))
            return (false);
    }
    return (true);
}

void    bitcoin_value(std::map<std::string, float> &bitcoin, char *filename)
{
    std::ifstream    file(filename);
    std::string str;

    while (std::getline(file, str)){
    try{
        if (str == "date | value")
            continue ;
        if (!good_format(str))
            throw ErrorBadInput(str.c_str());
        check_date(str);
        check_value(str);
        std::string str_value = str.substr(str.find('|') + 2);
        std::string str_date = str.erase(str.find(' '));
        std::map<std::string, float>::iterator it = bitcoin.lower_bound(str_date);
        if (it != bitcoin.begin() && bitcoin.find(str_date) == bitcoin.end())
            it--;
        std::cout << str_date << " => " << str_value << " = " << std::strtof(str_value.c_str(), NULL) * it->second << std::endl;
    }
    catch (ErrorBadInput &e){
        std::cerr << "Error: bad input => " << e.what() << std::endl;
    }
    catch(std::exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
    }
}