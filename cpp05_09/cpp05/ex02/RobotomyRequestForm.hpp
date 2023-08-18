#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm : public Form
{
public:

    RobotomyRequestForm(std::string target = "unknown");
    RobotomyRequestForm(RobotomyRequestForm const &b);
    ~RobotomyRequestForm();
    RobotomyRequestForm &operator=(RobotomyRequestForm const &b);

    void    execute_task(Bureaucrat const &b) const;
};

#endif