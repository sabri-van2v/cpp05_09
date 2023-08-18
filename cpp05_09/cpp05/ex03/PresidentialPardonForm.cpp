#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target):
Form("PresidentialPardon", target, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &b):Form(b)
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &b)
{
    Form::operator=(b);
    return (*this);
}

void    PresidentialPardonForm::execute_task(Bureaucrat const &b) const
{
    Form::execute(b);

    std::cout << Form::getTarget() << " was forgiven by Zaphod Beeblebrox" << std::endl;
}