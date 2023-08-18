#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
public:

    Intern();
    Intern(Intern const &i);
    ~Intern();
    Intern &operator=(Intern const &i);

    Form    *makeForm(std::string name, std::string target);

    class NameDoesNotExist : public std::exception
    {
        const char    *what() const throw()
        {
            return ("The name of Form does not exist");
        }
    };
};

#endif