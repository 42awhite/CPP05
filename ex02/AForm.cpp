#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructor
AForm::AForm() : _Name("EnBlanco"), _IsSigned(false), _GradeToSign(150), _GradeToExecute(150) {
}

// Constructor con parámetros
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: _Name(name), _IsSigned(false), _GradeToSign(gradeToSign), _GradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

// Destructor
AForm::~AForm() {
}

// Constructor de copia
AForm::AForm(const AForm &other) 
    : _Name(other._Name), _IsSigned(other._IsSigned), 
      _GradeToSign(other._GradeToSign), _GradeToExecute(other._GradeToExecute) {}

// Operador de asignación
AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        _IsSigned = other._IsSigned;
    }
    return *this;
}

// Getters
std::string AForm::getName() const { 
	return _Name; 
}

bool AForm::isSigned() const { 
	return _IsSigned; 
}

int AForm::getGradeToSign() const { 
	return _GradeToSign; 
}

int AForm::getGradeToExecute() const { 
	return _GradeToExecute; 
}

//Función Firma
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.GetGrade() > _GradeToSign)
		throw GradeTooLowException();
	_IsSigned = true;
}

// Operador de inserción <<
std::ostream &operator<<(std::ostream &o, const AForm &Aform) {
    o << "AForm: " << Aform.getName() 
      << " | Signed: " << (Aform.isSigned() ? "Yes" : "No") 
      << " | Grade to sign: " << Aform.getGradeToSign()
      << " | Grade to execute: " << Aform.getGradeToExecute();
    return o;
}
