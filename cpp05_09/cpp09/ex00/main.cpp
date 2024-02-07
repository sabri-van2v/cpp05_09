#include "BitcoinExchange.hpp"

void    parsing_arg(int argc, char **argv, const char *csvname)
{
    if (argc != 2)
        throw ErrorArg();
    std::ifstream    csv_file(csvname);
    std::ifstream    input(argv[1]);
    if (!csv_file.is_open() || !input.is_open())
        throw ErrorArg();
}

std::map<std::string, float>    parsing_csv(std::string filename)
{
    std::map<std::string, float>    bitcoin;
    std::ifstream                   csv(filename.c_str());
    std::string                     line, date, value;

    while (std::getline(csv, line))
    {
        if (line == "date,exchange_rate")
            continue ;
        std::istringstream line_stream(line);
        std::getline(line_stream, date, ',');
        std::getline(line_stream, value, '\n');
        bitcoin[date] = std::atof(value.c_str());
    }
    return (bitcoin);
}

int main(int argc, char **argv)
{
    std::map<std::string, float> bitcoin;

    try{
        parsing_arg(argc, argv, "data.csv");
        bitcoin = parsing_csv("data.csv");
        bitcoin_value(bitcoin, argv[1]);
    }
    catch (std::exception &e){
        std::cerr << "Error: " << e.what() << std::endl;
        return (1);
    }
}