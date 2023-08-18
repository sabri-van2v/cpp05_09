#include "ScalarConvert.hpp"

int ScalarConvert::impossible = VALIDE;

ScalarConvert::ScalarConvert()
{
    impossible = VALIDE;
}

ScalarConvert::ScalarConvert(ScalarConvert const &s)
{
    impossible = VALIDE;
    (void)s;
}

ScalarConvert::~ScalarConvert()
{}

ScalarConvert &ScalarConvert::operator=(ScalarConvert const &s)
{
    (void)s;
    return (*this);
}


void    ScalarConvert::ConvertChar(double &number)
{
    std::cout << "char : ";
    if (impossible == IMPOSSIBLE)
    {
        std::cout << "impossible" << std::endl;
        return ;
    }
    if (number >= -128 && number <= 127)
    {
        if (number > 31 && number < 127)
            std::cout << static_cast<char>(number) << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "overflow" << std::endl;
}

void    ScalarConvert::ConvertInt(double &number)
{
    std::cout << "int : ";
    if (impossible == IMPOSSIBLE)
    {
        std::cout << "impossible" << std::endl;
        return ;
    }
    if (number >= INT_MIN && number <= INT_MAX)
        std::cout << static_cast<int>(number) << std::endl;
    else
        std::cout << "overflow" << std::endl;
}

void    ScalarConvert::ConvertFloat(double &number)
{
    std::cout << "float : ";
    if (impossible == IMPOSSIBLE)
        std::cout << "nan";
    else
    {
        std::cout << static_cast<float>(number);
        out_dotzero(number);
    }
    std::cout << 'f' << std::endl;
}

void    ScalarConvert::ConvertDouble(double &number)
{
    std::cout << "double : ";
    if (impossible == IMPOSSIBLE)
    {
        std::cout << "nan" << std::endl;
        return ;
    }
    std::cout << number;
    out_dotzero(number);
    std::cout << std::endl;
}

void ScalarConvert::out_dotzero(double &number)
{
    std::ostringstream stream1;
    std::ostringstream stream2;
    stream1 << std::fixed << number;
    stream2 << number;
    std::string str1 = stream1.str();
    std::string str2 = stream2.str();
    if (str1.find_first_not_of("0", str1.find('.') + 1) == std::string::npos && str2.find('e') == std::string::npos)
        std::cout << ".0";
}

void ScalarConvert::check_str(std::string str)
{
    int i = 0;

    if (str[0] == '-')
        str = str.substr(1);
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (!str[i] || (str[i] == 'f' && !str[i + 1]))
        return ;
    if (str[i] != '.')
    {
        ScalarConvert::impossible = IMPOSSIBLE;
        return ;
    }
    i++;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] == 'f')
    {
        if (str.size() - 1 != (size_t)i)
            ScalarConvert::impossible = IMPOSSIBLE;
    }
    else
        if (str.size() != (size_t)i)
            ScalarConvert::impossible = IMPOSSIBLE;
}

void ScalarConvert::convert(std::string str)
{
    ScalarConvert::check_str(str);

    double number = std::strtod(str.c_str(), NULL);

    ScalarConvert::ConvertChar(number);
    ScalarConvert::ConvertInt(number);
    ScalarConvert::ConvertFloat(number);
    ScalarConvert::ConvertDouble(number);

    ScalarConvert::impossible = 0;
}
