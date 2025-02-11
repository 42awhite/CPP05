#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
private:
    const std::string _Name;
    bool _IsSigned;
    const int _GradeToSign;
    const int _GradeToExecute;

public:
    // Orthodox Canonical Form
    AForm();
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    virtual ~AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);

    // Getters
    std::string GetName() const;
    bool IsSigned() const;
    int GetGradeToSign() const;
    int GetGradeToExecute() const;

    // Función para que un Bureaucrat firme y ejecute el AForm
    void BeSigned(const Bureaucrat &bureaucrat);
    virtual void Execute(Bureaucrat const &executor) const = 0; // Método virtual puro

    // Excepciones
    class GradeTooHighException : public std::exception {
    public:
        const char *what() const throw() {
            return "AForm grade too high!";
        }
    };

    class GradeTooLowException : public std::exception {
    public:
        const char *what() const throw() {
            return "AForm grade too low!";
        }
    };

    class FormNotSignedException : public std::exception {
    public:
        const char *what() const throw() {
            return "Form is not signed!";
        }
    };
};


std::ostream &operator<<(std::ostream &o, const AForm &Aform);

#endif