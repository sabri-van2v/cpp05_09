#include "Form.hpp"

Form::Form(std::string name, std::string target, int grade_for_sign, int grade_for_execute):
_name(name), _target(target), _grade_for_execute(grade_for_execute),
_grade_for_sign(grade_for_sign), _signed(false)
{
    if (_grade_for_execute < 1 or _grade_for_sign < 1)
        throw (Form::GradeTooHighException());
    if (_grade_for_execute > 150 or _grade_for_sign > 150)
        throw (Form::GradeTooLowException());
}

Form::Form():_name("unknown"),
_target("unknown"),
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
    _target = b._target;
    return (*this);
}

std::string Form::getName() const
{
    return (_name);
}

std::string Form::getTarget() const
{
    return (_target);
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

void        Form::execute(Bureaucrat const & executor) const
{
    if (_signed == false)
        throw (Form::GradeFormNotSigned());
    if (executor.getGrade() > _grade_for_execute)
        throw (Form::GradeTooLowException());
}

std::ostream &operator<<(std::ostream &o, Form const &f)
{
    o << "name : " << f.getName();
    o << ", target : " << f.getTarget();
    o << ", status : " << (f.getSigned() == true ? "signed" : "not signed");
    o << ", grade for sign : " << f.getGradeForSign();
    o << ", grade for execute : " << f.getGradeForExecute();
    return (o);
}