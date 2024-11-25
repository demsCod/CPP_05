#include "AForm.hpp"

// Add also a beSigned() member function to the Form that takes a Bureaucrat as
// parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
// (higher or egal to the required one). Remember, grade 1 is higher than grade 2.
// If the grade is too low, throw a Form::GradeTooLowException.




void AForm::BeSigned(Bureaucrat& po)
{
	if (_IsSigned)
    	std::cout << "This "<< _name << " is already signed" << std::endl;
	if (po.getGrade() > _GradeRequiredToSign)
		throw AForm::GradeTooLowException();
	_IsSigned = true;
}

void AForm::BeExec(Bureaucrat& po)
{
	if (po.getGrade() > _GradeRequiredToExec)
		throw AForm::GradeTooLowException();
	_IsSigned = true;
}

bool AForm::GetStatus() const 
{
	return (_IsSigned);
}

std::string AForm::GetName() const 
{
	return _name;
}
AForm::AForm(std::string name, int grs, int gre) : _name(name),_GradeRequiredToSign(grs),  _GradeRequiredToExec(gre)
{
	std::cout << "AForm : " << _name << " has been created\n";
	_IsSigned = false;
}

AForm::~AForm()
{
	std::cout << "AForm : " << _name << " has been burned\n";
}

AForm::AForm(AForm& other) : _name(other.GetName()), _GradeRequiredToSign(other.getGts()), _GradeRequiredToExec(other.getGte())
{
	_IsSigned = other.GetStatus();
	std::cout << "AForm : " << _name << " has been copyed\n";
}


AForm& AForm::operator=(AForm& f)
{
	if (this != &f)
	{
		_IsSigned = f.GetStatus();
	}
	return (*this);
}


int AForm::getGte(void) const
{
	return _GradeRequiredToExec;
}

int AForm::getGts(void) const
{
	return _GradeRequiredToSign;
}

