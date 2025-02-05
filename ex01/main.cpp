#include "Bureaucrat.hpp"
#include "Form.hpp"

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat intern("Intern", 150);
        Form contract("Top Secret Contract", 50, 10);

        std::cout << contract << std::endl;

        // Intern intenta firmar (debería fallar)
        std::cout << "Intern intenta firmar el contrato..." << std::endl;
        intern.signForm(contract);

    } catch (std::exception &e) {
        std::cerr << "Error al firmar: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat boss("Boss", 1);
        Form contract("Top Secret Contract", 50, 10);

        // Boss firma el contrato correctamente
        std::cout << "Boss firma el contrato..." << std::endl;
        boss.signForm(contract);
        std::cout << contract << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Error al firmar: " << e.what() << std::endl;
    }

    return 0;
}



