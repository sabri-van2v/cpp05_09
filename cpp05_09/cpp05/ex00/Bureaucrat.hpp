#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
public :

    Bureaucrat(std::string name, int grade);

    Bureaucrat();
    Bureaucrat(Bureaucrat const &b);
    ~Bureaucrat();
    Bureaucrat &operator=(Bureaucrat const &b);

    std::string getName();
    int         getGrade();
    void        increment();
    void        decrement();

    class GradeTooHighException : public std::exception
    {
        const char *what() const throw()
        {
            return ("The grade is too high !");
        }
    };
    class GradeTooLowException : public std::exception
    {
        const char *what() const throw()
        {
            return ("The grade is too low !");
        }
    };

private :

    std::string const   _name;
    int                 _grade;
};

std::ostream    &operator<<(std::ostream &o, Bureaucrat &b);

#endif