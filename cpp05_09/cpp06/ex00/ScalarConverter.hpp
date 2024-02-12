#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <climits>
#include <cmath>
#include <cfloat>
#include <iomanip>

enum
{
    VALIDE,
    IMPOSSIBLE,
};

class ScalarConverter
{
public:

    static void     ConvertChar(double &number);
    static void     ConvertInt(double &number);
    static void     ConvertFloat(double &number);
    static void     ConvertDouble(double &number);

    static void     out_dotzero(double &number);
    static void     check_str(std::string str);

    static void convert(std::string str);

private:

    ScalarConverter();
    ScalarConverter(ScalarConverter const &s);
    ~ScalarConverter();
    ScalarConverter &operator=(ScalarConverter const &s);

    static int  impossible;
};

#endif