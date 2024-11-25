#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"
std::ostream& operator<<(std::ostream& os,  Bureaucrat& fx)
{
    os << fx.getName();
    os << ", bureaucrat grade ";
    os << fx.getGrade();
    return os;
}

int main ()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	try {
		RobotomyRequestForm d("random");
		ShrubberyCreationForm c("momo");
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("presidential pardon", "Bender");


		Bureaucrat B("zorro", 3);
		Bureaucrat C("luffy", 150);

		C.SignForm(d);
		C.executeForm(d);
		B.SignForm(d);
		C.executeForm(d);
		B.executeForm(d);
		B.executeForm(d);
		B.executeForm(d);
		B.executeForm(d);
		B.executeForm(d);
		B.executeForm(d);
		B.executeForm(d);
		C.executeForm(d);
		B.executeForm(d);
		B.executeForm(d);
		B.executeForm(d);
		B.executeForm(d);
		B.executeForm(d);
		B.executeForm(d);
		B.executeForm(d);
		B.executeForm(d);
		B.executeForm(d);
		B.executeForm(d);
		B.executeForm(d);
		B.executeForm(d);

		//C.SignForm(rrf);
		//C.executeForm(e);
		// B.SignForm(e);
		// C.executeForm(e);
		// B.executeForm(e);		
		B.IncrementGrade();
		B.SignForm(c);
		C.SignForm(c);
		C.executeForm(c);
		B.executeForm(c);
		std::cout << "-------------------------------------------------------------------------\n"; 	
		}


	catch(Bureaucrat::GradeTooHightException &e)
	{
		std::cout << e.what();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what();
	}
	catch(AForm::GradeTooLowException &e)
	{
		std::cout << e.what();
	}




}


