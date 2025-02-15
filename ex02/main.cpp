#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Crear un Bureaucrat con grado 50
        Bureaucrat bureaucrat("John", 40);

        // Crear instancias de formularios con diferentes targets
        ShrubberyCreationForm shrubbery(".");
        RobotomyRequestForm robotomy("Bender");
        PresidentialPardonForm pardon("Bob");

        // **Caso 1: Ejecutar ShrubberyCreationForm (debe fallar si no está firmado)**
        std::cout << "CASO 1: Testing ShrubberyCreationForm (no firmado):" << std::endl;
        try {
            bureaucrat.executeAForm(shrubbery); 
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl; 
        }

        // **Caso 2: Firmar ShrubberyCreationForm y luego ejecutarlo**
        std::cout << "\n CASO 2: Signing ShrubberyCreationForm and executing:" << std::endl;
        bureaucrat.signAForm(shrubbery);
        bureaucrat.executeAForm(shrubbery);

        // **Caso 3: Ejecutar RobotomyRequestForm (debe fallar si no está firmado)**
        std::cout << "\n CASO 3: Testing RobotomyRequestForm (no firmado):" << std::endl;
        try {
            bureaucrat.executeAForm(robotomy); 
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl; 
        }

        // **Caso 4: Firmar RobotomyRequestForm y luego ejecutarlo**
        std::cout << "\nCASO 4: Signing RobotomyRequestForm and executing:" << std::endl;
        bureaucrat.signAForm(robotomy);
        bureaucrat.executeAForm(robotomy);

        // **Caso 5: Ejecutar PresidentialPardonForm (debe fallar si no está firmado)**
        std::cout << "\n CASO 5: Testing PresidentialPardonForm (no firmado):" << std::endl;
        try {
            bureaucrat.executeAForm(pardon);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl; 
        }

        // **Caso 6: Firmar PresidentialPardonForm y ejecutarlo (sin el grado necesario)**
        std::cout << "\n CASO 6: Signing PresidentialPardonForm and executing (without enough grade):" << std::endl;
        bureaucrat.signAForm(pardon);
        try {
            bureaucrat.executeAForm(pardon);
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;  // Error por grado demasiado bajo
        }

        // **Caso 7: Crear un Bureaucrat con grado suficiente para ejecutar y probar el formulario**
        std::cout << "\n CASO 7: Testing with Bureaucrat of grade 5:" << std::endl;
        Bureaucrat bureaucrat2("Alice", 5); 
        bureaucrat2.signAForm(pardon);
        bureaucrat2.executeAForm(pardon);
    } 
    catch (std::exception &e) 
    {
        std::cerr << e.what() << std::endl;  // Captura excepciones generales
    }

    return 0;
}

