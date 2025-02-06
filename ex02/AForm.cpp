#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructor por defecto
AForm::AForm() : _Name("EnBlanco"), _IsSigned(false), _GradeToSign(150), _GradeToExecute(150) {}

// Constructor con parámetros
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
    : _Name(name), _IsSigned(false), _GradeToSign(gradeToSign), _GradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

// Destructor
AForm::~AForm() {}

// Constructor de copia
AForm::AForm(const AForm &other)
    : _Name(other._Name), _IsSigned(other._IsSigned),
      _GradeToSign(other._GradeToSign), _GradeToExecute(other._GradeToExecute) {}

// Operador de asignación
AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        _IsSigned = other._IsSigned; // No se pueden copiar los atributos const
    }
    return *this;
}

// Getters
std::string AForm::GetName() const {
    return _Name;
}

bool AForm::IsSigned() const {
    return _IsSigned;
}

int AForm::GetGradeToSign() const {
    return _GradeToSign;
}

int AForm::GetGradeToExecute() const {
    return _GradeToExecute;
}

// Función para firmar el AForm
void AForm::BeSigned(const Bureaucrat &bureaucrat) {
    if (bureaucrat.GetGrade() > _GradeToSign)
        throw GradeTooLowException();
    _IsSigned = true;
}

// Operador de inserción <<
std::ostream &operator<<(std::ostream &o, const AForm &Aform) {
    o << "AForm: " << Aform.GetName()
      << " | Signed: " << (Aform.IsSigned() ? "Yes" : "No")
      << " | Grade to sign: " << Aform.GetGradeToSign()
      << " | Grade to execute: " << Aform.GetGradeToExecute();
    return o;
}
