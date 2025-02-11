#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Constructor por defecto
PresidentialPardonForm::PresidentialPardonForm()
    : AForm("Presidential Pardon Form", 25, 5), _target("default") {}

// Constructor con parámetro
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("Presidential Pardon Form", 25, 5), _target(target) {}

// Constructor de copia
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), _target(other._target) {}

// Operador de asignación
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Método execute()
void PresidentialPardonForm::Execute(Bureaucrat const &executor) const {
    if (!this->AForm::IsSigned())  // Verifica si está firmado
        throw AForm::FormNotSignedException();
    if (executor.GetGrade() > this->GetGradeToExecute())  // Verifica si el Bureaucrat tiene el grado suficiente
        throw AForm::GradeTooLowException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

