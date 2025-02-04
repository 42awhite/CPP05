
#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat test("Miguel", 1);
	
		std::cout << test << std::endl;
		test.gradeIncrement();
		std::cout << test << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat test("Samu", 10);

		std::cout << test << std::endl;
		test.gradeIncrement();
		std::cout << test << std::endl;
		test.gradeDecrement();
		std::cout << test << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat test("Clara", 150);
	
		std::cout << test << std::endl;
		test.gradeDecrement();
		std::cout << test << std::endl;
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
