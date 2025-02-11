#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
    //as always:
    Intern();
    ~Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);

    //Función crear un formulario
    AForm *makeForm(std::string formName, std::string target);
};

#endif 
