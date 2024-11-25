#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <stdexcept>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

#include <ostream>
class AForm;

class Bureaucrat
{
	private :
		const std:: string _name;
		int _grade;
	public :
		class GradeTooHightException : public std::exception
		{
			public :
				GradeTooHightException() 
				{}
				virtual const char* what() const throw()
				{
					return "the grade is to hight\n";
				}
		};
		class GradeTooLowException : public std::exception
		{

			public :
				GradeTooLowException()
				{}
				virtual const char* what() const throw()
				{
					return " the grade is to low\n";
				}
		};
		Bureaucrat(std :: string name, int grade);
		int getGrade() const;
		const std::string getName() const;
		Bureaucrat& operator=(const  Bureaucrat& other);
		Bureaucrat(Bureaucrat& other);
		void IncrementGrade(void);
		void DecrementGrade(void);
		void SignForm(AForm& form);
		void executeForm(AForm const & form);
		~Bureaucrat();

};

#endif
