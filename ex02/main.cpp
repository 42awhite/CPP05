#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    try {
        // Crear un Bureaucrat con grado 50
        Bureaucrat bureaucrat("John", 50);

        // Crear instancias de formularios con diferentes targets
        ShrubberyCreationForm shrubbery("Home");
        RobotomyRequestForm robotomy("Alice");
        PresidentialPardonForm pardon("Bob");

        // **Caso 1: Ejecutar ShrubberyCreationForm (debe fallar si no está firmado)**
        std::cout << "Testing ShrubberyCreationForm (no firmado):" << std::endl;
        try {
            bureaucrat.executeAForm(shrubbery);  // Aquí fallará porque el formulario no está firmado
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;  // Debe imprimir error sobre formulario no firmado
        }

        // **Caso 2: Firmar ShrubberyCreationForm y luego ejecutarlo**
        std::cout << "\nSigning ShrubberyCreationForm and executing:" << std::endl;
        bureaucrat.signAForm(shrubbery);  // Firmamos el formulario
        bureaucrat.executeAForm(shrubbery);  // Ahora debería ejecutarse correctamente
        // Salida esperada: "Shrubbery created at Home_shrubbery"

        // **Caso 3: Ejecutar RobotomyRequestForm (debe fallar si no está firmado)**
        std::cout << "\nTesting RobotomyRequestForm (no firmado):" << std::endl;
        try {
            bureaucrat.executeAForm(robotomy);  // Aquí fallará si no está firmado
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;  // Error por formulario no firmado
        }

        // **Caso 4: Firmar RobotomyRequestForm y luego ejecutarlo**
        std::cout << "\nSigning RobotomyRequestForm and executing:" << std::endl;
        bureaucrat.signAForm(robotomy);  // Firmamos el formulario
        bureaucrat.executeAForm(robotomy);  // Ahora debería ejecutarse correctamente
        // Salida esperada: "Drilling noises..." seguido de éxito o fallo de la operación

        // **Caso 5: Ejecutar PresidentialPardonForm (debe fallar si no está firmado)**
        std::cout << "\nTesting PresidentialPardonForm (no firmado):" << std::endl;
        try {
            bureaucrat.executeAForm(pardon);  // Fallará porque no está firmado
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;  // Error por formulario no firmado
        }

        // **Caso 6: Firmar PresidentialPardonForm y ejecutarlo (sin el grado necesario)**
        std::cout << "\nSigning PresidentialPardonForm and executing (without enough grade):" << std::endl;
        bureaucrat.signAForm(pardon);  // Firmamos el formulario
        try {
            bureaucrat.executeAForm(pardon);  // Aquí fallará porque el Bureaucrat tiene grado 50, y necesita grado 25 para ejecutarlo
        } catch (std::exception &e) {
            std::cerr << "Error: " << e.what() << std::endl;  // Error por grado demasiado bajo
        }

        // **Caso 7: Crear un Bureaucrat con grado suficiente para ejecutar y probar el formulario**
        std::cout << "\nTesting with Bureaucrat of grade 25:" << std::endl;
        Bureaucrat bureaucrat2("Alice", 25);  // Crear un Bureaucrat con grado 25 (suficiente para ejecutar)
        bureaucrat2.executeAForm(pardon);  // Debería ejecutarse sin problemas
        // Salida esperada: "Bob has been pardoned by Zaphod Beeblebrox."

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;  // Captura excepciones generales
    }

    return 0;
}

