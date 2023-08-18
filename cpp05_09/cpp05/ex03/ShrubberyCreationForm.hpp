#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
public:

    ShrubberyCreationForm(std::string target = "unknown");
    ShrubberyCreationForm(ShrubberyCreationForm const &b);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm &operator=(ShrubberyCreationForm const &b);

    void    execute_task(Bureaucrat const &b) const;
};

#endif