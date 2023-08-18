#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	Bureaucrat				Mathilde("Mathilde", 100);
	Bureaucrat				Hugo("Hugo", 50);
	Bureaucrat				Sylvie("Sylvie", 1);

	ShrubberyCreationForm	S("garden");
	RobotomyRequestForm		R("dog");
	PresidentialPardonForm	P("Earth");

	Mathilde.executeForm(S);
	Hugo.executeForm(R);
	Sylvie.executeForm(S);

	std::cout << std::endl;

	Mathilde.signForm(S);
	Hugo.signForm(S);
	Sylvie.signForm(S);

	std::cout << std::endl;

	Mathilde.signForm(R);
	Hugo.signForm(R);
	Sylvie.signForm(R);

	std::cout << std::endl;

	Mathilde.signForm(P);
	Hugo.signForm(P);
	Sylvie.signForm(P);

	std::cout << std::endl;

	Mathilde.executeForm(S);
	Hugo.executeForm(S);
	Sylvie.executeForm(S);

	std::cout << std::endl;

	Mathilde.executeForm(R);
	Hugo.executeForm(R);
	Sylvie.executeForm(R);

	std::cout << std::endl;

	Mathilde.executeForm(P);
	Hugo.executeForm(P);
	Sylvie.executeForm(P);
}