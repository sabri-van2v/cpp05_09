#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):
Form("RobotomyRequest", target, 72, 45)
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &b):Form(b)
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &b)
{
    Form::operator=(b);
    return (*this);
}

void    RobotomyRequestForm::execute_task(Bureaucrat const &b) const
{
    Form::execute(b);

    std::cout << "vrrrrrrrr" << std::endl;
    if (rand() % 2 == 0)
        std::cout << Form::getTarget() << " has been robotized" << std::endl;
    else
        std::cout << "the operation failed on " << Form::getTarget() << std::endl;
}