#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

// Constructor por defecto
ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("Shrubbery Creation Form", 145, 137), _target("default") {}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Constructor de copia
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), _target(other._target) {}

// Operador de asignación
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

// Método execute
void ShrubberyCreationForm::Execute(Bureaucrat const &executor) const {
    if (!this->AForm::IsSigned())  // Verifica si está firmado
        throw AForm::FormNotSignedException();  // Utiliza la excepción correcta
    if (executor.GetGrade() > this->GetGradeToExecute())  // Verifica si el Bureaucrat tiene el grado suficiente
        throw AForm::GradeTooLowException();

    // Crear el archivo de "arbustos"
    std::ofstream outFile(_target + "_shrubbery");
    //std::ofstream outFile(_target + "_shrubbery");
outFile << "        ASCII Trees" << std::endl;
outFile << "        ^" << std::endl;
outFile << "       ^^^" << std::endl;
outFile << "      ^^^^^" << std::endl;
outFile << "     ^^^^^^^" << std::endl;
outFile << "    ^^^^^^^^^" << std::endl;
outFile << "   ^^^^^^^^^^^" << std::endl;
outFile << "  ^^^^^^^^^^^^^" << std::endl;
outFile << " ^^^^^^^^^^^^^^^" << std::endl;
outFile << "^^^^^^^^^^^^^^^^^" << std::endl;
outFile << "       |||" << std::endl;
outFile << "       |||" << std::endl;
outFile << "       |||" << std::endl;
outFile.close();

    std::cout << "Shrubbery created at " << _target << "_shrubbery" << std::endl;
}
