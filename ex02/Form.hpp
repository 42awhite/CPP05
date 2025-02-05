#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

// Declaración adelantada (soluciona el problema de inclusión circular)
class Bureaucrat;  

class Form {
private:
	const std::string _Name;
	bool _IsSigned;
	const int _GradeToSign;
	const int _GradeToExecute;
public:
    //as always
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);

	// Getters
	std::string getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	// Función para que un Bureaucrat firme el Form
    void beSigned(const Bureaucrat &bureaucrat);

	//Excepciones
	class GradeTooHighException : public std::exception{
		public:
			const char *what() const throw(){
				return "Form grade too high!";
			}
	};
		class GradeTooLowException : public std::exception{
		public:
			const char *what() const throw(){
				return "Form grade too low!";
			}
	};

};

std::ostream &operator<<(std::ostream &o, const Form &form);

#endif // FORM_HPP
