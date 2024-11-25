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
		Bureaucrat B("zorro", 1);
		std::cout << B << std::endl;
		Bureaucrat A("luffy", 1088);
		Bureaucrat O(A);
		Bureaucrat D("ussop", 148);
		Bureaucrat F("chopper", 3);
		F.IncrementGrade();
		D.DecrementGrade();
		D.DecrementGrade();
		D.DecrementGrade();


		F.IncrementGrade();
		F.IncrementGrade();

		std::cout << "-------------------------------------------------------------------------\n"; 	}
	catch(Bureaucrat::GradeTooHightException &e)
	{
		std::cout << e.what();
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what();
	}





}


