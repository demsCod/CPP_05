#include "Form.hpp"

// Add also a beSigned() member function to the Form that takes a Bureaucrat as
// parameter. It changes the form status to signed if the bureaucrat’s grade is high enough
// (higher or egal to the required one). Remember, grade 1 is higher than grade 2.
// If the grade is too low, throw a Form::GradeTooLowException.




void Form::BeSigned(Bureaucrat& po)
{
	if (_IsSigned)
    	std::cout << "This form is already signed" << std::endl;
	if (po.getGrade() > _GradeRequiredToSign)
		throw Form::GradeTooLowException();
	_IsSigned = true;
}

void Form::BeExec(Bureaucrat& po)
{
	if (po.getGrade() > _GradeRequiredToExec)
		throw Form::GradeTooLowException();
	_IsSigned = true;
}

 bool Form::GetStatus() const 
{
	return (_IsSigned);
}

const std::string Form::GetName() const
{
	return _name;
}
Form::Form(std::string name, int grs, int gre) : _name(name) ,_GradeRequiredToSign(grs), _GradeRequiredToExec(gre)
{
	std::cout << "Form : " << _name << " has been created\n";
	_IsSigned = false;
}

Form::~Form()
{
	std::cout << "Form : " << _name << " has been burned\n";
}

Form::Form(const Form& other) : _name(other.GetName()) ,_GradeRequiredToSign(other.getGts()) , _GradeRequiredToExec(other.getGte())
{
	_IsSigned = other.GetStatus();
	std::cout << "Form : " << _name << " has been copyed\n";
}

int Form::getGte(void) const
{
	return _GradeRequiredToExec;
}

int Form::getGts(void) const
{
	return _GradeRequiredToSign;
}


Form& Form::operator=(Form& f)
{
	if (this != &f)
	{
		_IsSigned = f.GetStatus();
	}
	return (*this);
}