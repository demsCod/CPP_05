#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <stdexcept>
#include <string>
#include <iostream>
#include <ostream>


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
					return "error ! the grade is to hight\n";
				}
		};
		class GradeTooLowException : public std::exception
		{

			public :
				GradeTooLowException()
				{}
				virtual const char* what() const throw()
				{
					return "error ! the grade is to low\n";
				}
		};
		Bureaucrat(std :: string name, int grade);
		int getGrade() const;
		const std::string getName() const;
		Bureaucrat& operator=( Bureaucrat& other);
		Bureaucrat(Bureaucrat& other);
		void IncrementGrade(void);
		void DecrementGrade(void);
		~Bureaucrat();

};

#endif
