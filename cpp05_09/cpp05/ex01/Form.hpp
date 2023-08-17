#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:

    Form(std::string name = "unknown", int grade_for_sign = 150, int grade_for_execute = 150);

    Form();
    Form(Form const &b);
    ~Form();
    Form &operator=(Form const &b);

    std::string getName() const;
    bool        getSigned() const;
    int         getGradeForSign() const;
    int         getGradeForExecute() const;
    void        beSigned(Bureaucrat b);

    class GradeTooHighException : public std::exception
    {
        const char *what() const throw()
        {
            return ("'Form : The grade is too high !'");
        }
    };
    class GradeTooLowException : public std::exception
    {
        const char *what() const throw()
        {
            return ("'Form : The grade is too low !'");
        }
    };

private:

    std::string const   _name;
    int const           _grade_for_execute;
    int const           _grade_for_sign;
    bool                _signed;
};

std::ostream &operator<<(std::ostream &o, Form const &f);

#endif