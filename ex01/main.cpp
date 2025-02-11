#include "Bureaucrat.hpp"
#include "Form.hpp"

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat intern("Pringao", 150);
        Form contract("Top Secret Contract", 50, 10);

        std::cout << contract << std::endl;

        std::cout << "Pringao intenta firmar el contrato..." << std::endl;
        intern.signForm(contract);

    } catch (std::exception &e) {
        std::cerr << "Error al firmar: " << e.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        Bureaucrat boss("Boss", 1);
        Form contract("Top Secret Contract", 50, 10);

        std::cout << "Boss firma el contrato..." << std::endl;
        boss.signForm(contract);
        std::cout << contract << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Error al firmar: " << e.what() << std::endl;
    }

    return 0;
}



