#include "Intern.hpp"

Intern::Intern(){}

Intern::Intern(Intern const &i){(void)i;}

Intern::~Intern(){}

Intern &Intern::operator=(Intern const &i)
{
    (void)i;
    return (*this);
}


Form    *Intern::makeForm(std::string name, std::string target)
{
    Form *ptr;

    std::string type_name[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    int i = 0;
    while (i < 3 && type_name[i] != name)
        i++;
    switch (i)
    {
        case 0:
            ptr = new ShrubberyCreationForm(target);
            break ;
        case 1:
            ptr = new RobotomyRequestForm(target);
            break ;
        case 2:
            ptr = new PresidentialPardonForm(target);
            break ;
        default:
            throw (NameDoesNotExist());
    }
    std::cout << "Intern creates " << *ptr << std::endl;
    return (ptr);
}
