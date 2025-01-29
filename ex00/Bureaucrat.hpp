#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

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
    int GetGrade();

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

#endif // BUREAUCRAT_HPP
