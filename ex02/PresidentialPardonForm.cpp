#include "PresidentialPardonForm.hpp"
#include <ostream>
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 72, 45), _target(target)
{
	std::cout << "A PresidentialPardonForm with target : " << _target << " has been created\n";
}

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 72, 45)
{
	_target = "default";
	std::cout << "A PresidentialPardonForm with target : " << _target << " has been created\n";
}


std::string PresidentialPardonForm::getTar()const
{
	return _target;
}


PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm("PresidentialPardonForm", 72, 45)
{
	_target = other.getTar();
	std::cout << "A PresidentialPardonForm with target : " << _target << " has been copied\n";
}


PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	if (this != &other)
	{
		_target = other.getTar();
	}
	return (*this);
}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
		if (!AForm::GetStatus())
			throw AForm::NotSigned();
		if (executor.getGrade() > AForm::getGte())
			throw AForm::GradeTooLowException();
		std::cout <<  _target << " has been pardoned by Zaphod Beeblebrox\n"; 	
}