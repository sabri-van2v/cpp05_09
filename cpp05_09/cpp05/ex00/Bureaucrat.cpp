#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade):_name(name)
{
    if (grade > 150)
        throw (Bureaucrat::GradeTooLowException());
    else if (grade < 1)
        throw (Bureaucrat::GradeTooHighException());
    else
        _grade = grade;
}

Bureaucrat::Bureaucrat():_name("unknown"), _grade(150)
{}

Bureaucrat::Bureaucrat(Bureaucrat const &b):_name(b._name)
{
    *this = b;
}

Bureaucrat::~Bureaucrat()
{}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &b)
{
    _grade = b._grade;
    return (*this);
}

std::string Bureaucrat::getName()
{
    return (_name);
}

int         Bureaucrat::getGrade()
{
    return (_grade);
}

void        Bureaucrat::increment()
{
    if (_grade == 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;
}

void        Bureaucrat::decrement()
{
    if (_grade == 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

std::ostream    &operator<<(std::ostream &o, Bureaucrat &b)
{
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return (o);
}