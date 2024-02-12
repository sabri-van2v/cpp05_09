#include "ScalarConverter.hpp"

int ScalarConverter::impossible = VALIDE;

ScalarConverter::ScalarConverter()
{
    impossible = VALIDE;
}

ScalarConverter::ScalarConverter(ScalarConverter const &s)
{
    impossible = VALIDE;
    (void)s;
}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &s)
{
    (void)s;
    return (*this);
}


void    ScalarConverter::ConvertChar(double &number)
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

void    ScalarConverter::ConvertInt(double &number)
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

void    ScalarConverter::ConvertFloat(double &number)
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

void    ScalarConverter::ConvertDouble(double &number)
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

void ScalarConverter::out_dotzero(double &number)
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

void ScalarConverter::check_str(std::string str)
{
    int i = 0;

    if (str[0] == '-')
        str = str.substr(1);
    if (!(str[i] >= '0' && str[i] <= '9'))
    {
        ScalarConverter::impossible = IMPOSSIBLE;
        return ;
    }
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (!str[i] || (str[i] == 'f' && !str[i + 1]))
        return ;
    if (str[i] != '.')
    {
        ScalarConverter::impossible = IMPOSSIBLE;
        return ;
    }
    i++;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] == 'f')
    {
        if (str.size() - 1 != (size_t)i)
            ScalarConverter::impossible = IMPOSSIBLE;
    }
    else
        if (str.size() != (size_t)i)
            ScalarConverter::impossible = IMPOSSIBLE;
}

void ScalarConverter::convert(std::string str)
{
    ScalarConverter::check_str(str);

    double number = std::strtod(str.c_str(), NULL);

    ScalarConverter::ConvertChar(number);
    ScalarConverter::ConvertInt(number);
    ScalarConverter::ConvertFloat(number);
    ScalarConverter::ConvertDouble(number);

    ScalarConverter::impossible = 0;
}
