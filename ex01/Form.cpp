#include "Form.hpp"

// Constructor
Form::Form() _Name("EnBlanco"), _IsSigned(false), _GradeToSign(150), _GradeToExecute(150) {
}

// Constructor con parámetros
Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: _Name(name), _IsSigned(false), _GradeToSign(gradeToSign), _GradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

// Destructor
Form::~Form() {
}

// Constructor de copia
Form::Form(const Form &other) 
    : _Name(other._Name), _IsSigned(other._IsSigned), 
      _GradeToSign(other._GradeToSign), _GradeToExecute(other._GradeToExecute) {}

// Operador de asignación
Form &Form::operator=(const Form &other) {
    if (this != &other) {
        _IsSigned = other._IsSigned;
    }
    return *this;
}

// Getters
std::string Form::getName() const { 
	return _name; 
}

bool Form::isSigned() const { 
	return _IsSigned; 
}

int Form::getGradeToSign() const { 
	return _GradeToSign; 
}

int Form::getGradeToExecute() const { 
	return _GradeToExecute; 
}

//Función Firma
void Form:beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.GetGrade() > _GradeToSign)
		throw GradeTooLowException();
	_IsSigned = true;
}

// Operador de inserción <<
std::ostream &operator<<(std::ostream &o, const Form &form) {
    o << "Form: " << form.getName() 
      << " | Signed: " << (form.isSigned() ? "Yes" : "No") 
      << " | Grade to sign: " << form.getGradeToSign()
      << " | Grade to execute: " << form.getGradeToExecute();
    return o;
}
