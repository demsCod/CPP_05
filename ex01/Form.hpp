
#ifndef FORM_CPP
#define FORM_CPP


#include "Bureaucrat.hpp"
#include <string>
class Bureaucrat;
class Form{
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
		~Form();
		Form(std::string name, int grs, int gre);
		Form& operator=(Form& f);
		Form(const Form& other);

		int getGte(void) const;
		int getGts(void) const;

		void BeSigned(Bureaucrat& po);
		void BeExec(Bureaucrat& po);
		bool GetStatus() const ;
		const std::string GetName()const ;




};

#endif