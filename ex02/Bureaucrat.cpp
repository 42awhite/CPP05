#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Constructor
Bureaucrat::Bureaucrat() : _Name("") {
	_Grade = 150;
}

// Constructor
Bureaucrat::Bureaucrat(std::string const Name, int Grade) : _Name(Name) {
	if (Grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (Grade > 150)
		throw(Bureaucrat::GradeTooLowException());
	else
		_Grade = Grade;
}

// Destructor
Bureaucrat::~Bureaucrat() {
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : _Name(other._Name) {
	    _Grade = other._Grade;
    std::cout << "Bureaucrat copy constructor called." << std::endl;
}

// Copy assignment operator
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &other) {
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

//Getter name
std::string Bureaucrat::GetName() const{
	return(_Name);
}

//getter Grade
int Bureaucrat::GetGrade() const{
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

void Bureaucrat::signAForm(AForm &AForm) {
    try {
        AForm.BeSigned(*this);
        std::cout << _Name << " signed " << AForm.GetName() << std::endl;
    } catch (std::exception &e) {
        std::cout << _Name << " couldn’t sign " << AForm.GetName() 
                  << " because " << e.what() << std::endl;
    }
}

std::ostream&	operator<<(std::ostream &o, const Bureaucrat &Burocrata) 
{
	o << Burocrata.GetName() << ", bureaucrat grade" << Burocrata.GetGrade();
	return o;
}

void Bureaucrat::executeAForm(AForm const &AForm) const {
    try {
        AForm.Execute(*this);
        std::cout << this->GetName() << " executed " << AForm.GetName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->GetName() << " couldn't execute " << AForm.GetName()
                  << " because " << e.what() << std::endl;
    }
}
