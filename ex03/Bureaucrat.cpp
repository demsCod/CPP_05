#include "Bureaucrat.hpp"


int Bureaucrat::getGrade() const
{
	return _grade;
}

const std::string Bureaucrat::getName()  const
{
	return _name;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{

	if (grade < 1) 
			throw Bureaucrat::GradeTooHightException();
	if (grade > 150) 
			throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << "The bureaucrat " << _name <<  " with grade : " << _grade << " has been created\n"; 

}
void Bureaucrat::IncrementGrade(void)
{
	if ((_grade - 1) < 1)
		throw Bureaucrat :: GradeTooHightException();
	std::cout << "Grade of " << _name << " changed positively : [" << _grade << "]-->" << "[" << (_grade - 1) <<"]\n";
	_grade--;
}

void Bureaucrat::DecrementGrade(void)
{
	if ((_grade + 1) > 150)
		throw Bureaucrat :: GradeTooLowException();
	std::cout << "Grade of " << _name << " changed negatively : [" << _grade << "]-->" << "[" << (_grade + 1) <<"]\n";
	_grade++;
}


Bureaucrat::~Bureaucrat()
{
	std::cout << "The bureaucrat " << _name <<  " with grade : " << _grade << " has been destroy\n"; 
}

Bureaucrat::Bureaucrat(Bureaucrat& other) : _name(other.getName())
{
	*this = other;
	std::cout << "The bureaucrat " << _name <<  " with grade : " << _grade << " has been copyed\n"; 

}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other.getGrade();
	}
	return *this;
}

// Lastly, add a signForm() member function to the Bureaucrat. If the form got signed,
// it will print something like:
// <bureaucrat> signed <form>
// Otherwise, it will print something like:
// <bureaucrat> couldn’t sign <form> because <reason>.
// Implement and turn in some tests to ensure everything works as expected.

void Bureaucrat::SignForm(AForm& form)
{
	try{
		form.BeSigned(*this);
		std::cout << _name << " signed " << form.GetName() << std::endl;
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout << _name << " couldn't sign " << form.GetName() << " because"<< e.what();
	}

	// if (form.GetStatus())
	// form.BeSigned(*this);
	// form.GetStatus();
	// std::cout << _name << " signed " << form.GetName() << std::endl;
	// std::cout << _name << " couldn't sign " << form.GetName() << "because " << "his grade is too low" << std::endl;
		
}


void Bureaucrat::executeForm(AForm const & form)
{
	try{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.GetName() << std::endl;  
	}
	catch (AForm::GradeTooLowException& e)
	{
		std::cout << this->getName() << " with grade " << this->getGrade() <<" can't execute " << form.GetName() << e.what() << std::endl;
	}
	catch (AForm::NotSigned& e)
	{
		std::cout << this->getName() << " with grade " << this->getGrade() <<" can't execute " << form.GetName() << e.what() << std::endl;
	}
}
