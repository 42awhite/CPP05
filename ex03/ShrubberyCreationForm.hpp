#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"  // Asegúrate de incluir la clase base AForm
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm {  // Herencia de AForm
private:
    std::string _target;  // El target, donde se creará el archivo

public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

    // Método override
    void Execute(Bureaucrat const &executor) const override;  // Asegúrate de usar 'execute' como en la clase base
};

#endif // SHRUBBERYCREATIONFORM_HPP


