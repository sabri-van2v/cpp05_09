#include "Form.hpp"

Form::Form(std::string name, int grade_for_sign, int grade_for_execute):_name(name),
_grade_for_execute(grade_for_execute), _grade_for_sign(grade_for_sign), _signed(false)
{
    if (_grade_for_execute < 1 or _grade_for_sign < 1)
        throw (GradeTooHighException());
    if (_grade_for_execute > 150 or _grade_for_sign > 150)
        throw (GradeTooLowException());
}

Form::Form():_name("unknown"),
_grade_for_execute(150),
_grade_for_sign(150),
_signed(false)
{}

Form::Form(Form const &b):_name(b._name),
_grade_for_execute(b._grade_for_execute),
_grade_for_sign(b._grade_for_sign)
{
    *this = b;
}

Form::~Form()
{}

Form &Form::operator=(Form const &b)
{
    _signed = b._signed;
    return (*this);
}

std::string Form::getName() const
{
    return (_name);
}

bool Form::getSigned() const
{
    return (_signed);
}

int   Form::getGradeForSign() const
{
    return (_grade_for_sign);
}

int   Form::getGradeForExecute() const
{
    return (_grade_for_execute);
}

void    Form::beSigned(Bureaucrat b)
{
    if (_signed == false)
    {
        if (b.getGrade() > _grade_for_sign)
            throw (Form::GradeTooLowException());
        _signed = true;
    }
}

std::ostream &operator<<(std::ostream &o, Form const &f)
{
    o << "name : " << f.getName();
    o << ", status : " << (f.getSigned() == true ? "signed" : "not signed");
    o << ", grade for sign : " << f.getGradeForSign();
    o << ", grade for execute : " << f.getGradeForExecute();
    return (o);
}