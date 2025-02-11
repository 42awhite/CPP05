#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    Intern someRandomIntern;
    AForm *form;

    form = someRandomIntern.makeForm("robotomy request", "Bender");
    delete form;

    form = someRandomIntern.makeForm("shrubbery creation", ".");
    delete form;

    form = someRandomIntern.makeForm("presidential pardon", "Condenado");
    delete form;

    form = someRandomIntern.makeForm("unknown form", "unknown person"); // Error esperado
    delete form;

    std::cout << "\n--- Prueba ciclo completo de un informe ---\n" << std::endl;
    Bureaucrat bureaucrat("Givememoney", 5);
    AForm *form1 = someRandomIntern.makeForm("robotomy request", "Bender");
        if (form1) {
            bureaucrat.signAForm(*form1);
            bureaucrat.executeAForm(*form1);
            delete form1;
        }

    return 0;
}


