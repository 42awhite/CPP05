#include "Intern.hpp"

Intern::Intern() {}
Intern::Intern(const Intern &other) 
{ 
    (void)other; 
}
Intern &Intern::operator=(const Intern &other) 
{ 
    (void)other; 
    return *this; 
}
Intern::~Intern() {}

AForm *Intern::makeForm(std::string formName, std::string target) {
    std::string formNames[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm *forms[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };
    for (int i = 0; i < 3; i++) 
    {
       if (formName == formNames[i]) 
       {
           std::cout << "Intern creates " << formName << std::endl;
           for (int j = 0; j < 3; j++) 
           {
               if (j != i) 
                    delete forms[j]; // Liberar los otros objetos no usados
           }
           return forms[i];
       }
    }
    std::cout << "Error: Form name '" << formName << "' is unknown." << std::endl;
    for (int i = 0; i < 3; i++)
        delete forms[i]; // Liberar todos si no se encontró ninguno
    return nullptr;
}
