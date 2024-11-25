
#ifndef AFORM_CPP
#define AFORM_CPP


#include "Bureaucrat.hpp"

#include <string>
class Bureaucrat;
class AForm{
	private :
		const std::string _name;
		bool _IsSigned;
		const int _GradeRequiredToSign;
		const int _GradeRequiredToExec;
	public :
		class GradeTooLowException : public std::exception
		{

			public :
				GradeTooLowException()
				{}
				virtual const char* what() const throw()
				{
					return " the grade is too low !\n";
				}
		};
		class AlreadySigned : public std::exception
		{

			public :
				AlreadySigned()
				{}
				virtual const char* what() const throw()
				{
					return " the contract is already signed\n";
				}
		};
		class NotSigned : public std::exception
		{

			public :
				NotSigned()
				{}
				virtual const char* what() const throw()
				{
					return " the contract is not signed\n";
				}
		};
		virtual ~AForm();
		AForm(std::string name, int grs, int gre);
		AForm& operator=(AForm& f);
		AForm(AForm& other);
		void BeSigned(Bureaucrat& po) ;
		void BeExec(Bureaucrat& po);
		virtual void execute(Bureaucrat const & executor) const = 0;
		bool GetStatus() const ;
		std::string GetName() const ;
		int getGte(void) const;
		int getGts(void) const;


};

#endif