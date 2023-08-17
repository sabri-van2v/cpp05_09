#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat john("John", 5);

	std::cout << john << std::endl;

	try
	{
		john.increment();
		john.increment();
		std::cout << john << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Form test("test", 151, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Cannot initialize test because " << e.what() << std::endl;
	}

	Form a("a");
	Form b("b", 3, 3);
	Form c("c", 2, 20);
	std::cout << john << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	john.signForm(a);
	john.signForm(b);
	john.signForm(b);
	
	try
	{
		john.decrement();
		std::cout << john << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	john.signForm(c);
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
}