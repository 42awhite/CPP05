#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("Robotomy Request Form", 72, 45), _target("default") {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), _target(other._target) {}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

void RobotomyRequestForm::Execute(Bureaucrat const &executor) const {
    if (!this->IsSigned())
        throw AForm::FormNotSignedException();  // Si no está firmado
    if (executor.GetGrade() > this->GetGradeToExecute())
        throw AForm::GradeTooLowException();  // Si el grado es demasiado bajo

    std::cout << "Drilling noises..." << std::endl;
    srand(time(NULL));
    int success = rand() % 2;
    if (success)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed for " << _target << "." << std::endl;
}

