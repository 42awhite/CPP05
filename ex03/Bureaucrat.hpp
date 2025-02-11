#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

#include "AForm.hpp"

class Bureaucrat {

private:
    std::string const _Name;
    int _Grade;

public:
    Bureaucrat();
    Bureaucrat(std::string const Name, int Grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);

    //getters
    std::string GetName() const;
    int GetGrade()const;
    void gradeIncrement();
    void gradeDecrement();

    //Firma
    void signAForm(AForm &Aform);
    void executeAForm(AForm const &Aform) const;



    //Clase excepciones
    class GradeTooHighException : public std::exception
    {
        public:
            const char *what() const throw()
            {
                return("Grade too high, deja de acumular poder");
            }
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw()
            {
                return("Grade too low, necesita dinero pobrecico");
            }

    };
};

std::ostream&	operator<<(std::ostream &o, Bureaucrat const &fixed);

#endif // BUREAUCRAT_HPP
