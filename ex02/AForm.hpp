#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

// Declaración adelantada (soluciona el problema de inclusión circular)
class Bureaucrat;  

class AForm {
private:
	const std::string _Name;
	bool _IsSigned;
	const int _GradeToSign;
	const int _GradeToExecute;
public:
    //as always
	AForm();
	AForm(std::string name, int gradeToSign, int gradeToExecute);
	virtual ~AForm();
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);

	// Getters
	std::string getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	// Función para que un Bureaucrat firme el AForm
    void beSigned(const Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0; // Método virtual puro

	//Excepciones
	class GradeTooHighException : public std::exception{
		public:
			const char *what() const throw(){
				return "AForm grade too high!";
			}
	};
		class GradeTooLowException : public std::exception{
		public:
			const char *what() const throw(){
				return "AForm grade too low!";
			}
	};

};

std::ostream &operator<<(std::ostream &o, const AForm &Aform);

#endif // AFORM_HPP
