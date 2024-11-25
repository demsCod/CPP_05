#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os,  Bureaucrat& fx)
{
    os << fx.getName();
    os << ", bureaucrat grade ";
    os << fx.getGrade();
    return os;
}

int main ()
{

	try {
		Bureaucrat B("zorro", 3);
		Bureaucrat C("luffy", 3);

		Form c("CONTRACT", 2, 2);
		B.IncrementGrade();
		B.SignForm(c);
		C.SignForm(c);
	
		std::cout << "-------------------------------------------------------------------------\n"; 	}
	catch(Bureaucrat::GradeTooHightException &e)
	{
		std::cout << e.what();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what();
	}
	catch(Form::GradeTooLowException &e)
	{
		std::cout << e.what();
	}




}


