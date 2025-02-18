#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _Name("") {
	// Constructor
	_Grade = 150;
}

Bureaucrat::Bureaucrat(std::string const Name, int Grade) : _Name(Name) {
	// Constructor
	if (Grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (Grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	else
		_Grade = Grade;
}

Bureaucrat::~Bureaucrat() {
	// Destructor
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _Name(other._Name) {
	// Copy constructor
	    _Grade = other._Grade;
    std::cout << "Bureaucrat copy constructor called." << std::endl;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &other) {
	// Copy assignment operator
	if (this != &other) {
		if (other._Grade < 1)
			throw (Bureaucrat::GradeTooHighException());
		if (other._Grade > 150)
			throw(Bureaucrat::GradeTooLowException());
		else
			_Grade = other._Grade;
	}
	std::cout << "Bureaucrat copy assignment operator called." << std::endl;
	return *this;
}

std::string Bureaucrat::GetName() const{
	//Getter name
	return(_Name);
}

int Bureaucrat::GetGrade() const{
	//getter Grade
	return(_Grade);
}

void Bureaucrat::gradeDecrement()
{
	if (_Grade >= 150)
		throw(Bureaucrat::GradeTooLowException());
	else
		_Grade++;
}

void Bureaucrat::gradeIncrement()
{
	if (_Grade <= 1)
		throw(Bureaucrat::GradeTooHighException());
	else
		_Grade--;
}

std::ostream&	operator<<(std::ostream &o, const Bureaucrat &Burocrata) 
{
	o << Burocrata.GetName() << ", bureaucrat grade " << Burocrata.GetGrade();
	return o;
}
