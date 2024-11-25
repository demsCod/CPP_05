#include "Bureaucrat.hpp"


int Bureaucrat::getGrade() const
{
	return _grade;
}

const std::string Bureaucrat::getName() const
{
	return _name;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{

	if (grade < 1) 
			throw Bureaucrat::GradeTooLowException();
	if (grade > 150) 
			throw Bureaucrat::GradeTooHightException();
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

Bureaucrat::Bureaucrat(Bureaucrat& other)
{
	*this = other;
	std::cout << "The bureaucrat " << _name <<  " with grade : " << _grade << " has been copyed\n"; 

}
Bureaucrat& Bureaucrat::operator=(Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other.getGrade();
	}
	return *this;
}


