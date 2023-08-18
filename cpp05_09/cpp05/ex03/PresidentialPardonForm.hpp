#ifndef PresidentialPardonForm_HPP
#define PresidentialPardonForm_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
public:

    PresidentialPardonForm(std::string target = "unknown");
    PresidentialPardonForm(PresidentialPardonForm const &b);
    ~PresidentialPardonForm();
    PresidentialPardonForm &operator=(PresidentialPardonForm const &b);

    void    execute_task(Bureaucrat const &b) const;
};

#endif