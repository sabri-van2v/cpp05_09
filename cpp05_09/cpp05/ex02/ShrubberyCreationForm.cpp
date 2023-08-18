#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target):
Form("ShruberryCreation", target, 145, 137)
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &b):Form(b)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &b)
{
    Form::operator=(b);
    return (*this);
}

void    ShrubberyCreationForm::execute_task(Bureaucrat const &b) const
{
    Form::execute(b);

    std::ofstream o((Form::getTarget() + "_shrubbery").c_str(), std::ios_base::app);
    if (o.fail())
        throw (std::ofstream::failure("Failed to open file"));

    o << "   ^   " << std::endl;
    o << "  ^^^  " << std::endl;
    o << " ^^^^^ " << std::endl;
    o << "^^^^^^^" << std::endl;
    o << "  |||  " << std::endl;
}