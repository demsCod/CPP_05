#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;
class Intern
{
	public :
		AForm *makeForm(std::string name, std::string target);
		class InvalidNameException : public std::exception
		{
			public :
				InvalidNameException() 
				{}
				virtual const char* what() const throw()
				{
					return "this name form doesnt exit\n";
				}
		};
};