#include "RobotomyRequestForm.hpp"
#include <ostream>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "A RobotomyRequestForm with target : " << _target << " has been created\n";
}

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	_target = "default";
	std::cout << "A RobotomyRequestForm with target : " << _target << " has been created\n";
}


std::string RobotomyRequestForm::getTar()const
{
	return _target;
}


RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = other.getTar();
	std::cout << "A RobotomyRequestForm with target : " << _target << " has been copied\n";
}


RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	if (this != &other)
	{
		_target = other.getTar();
	}
	return (*this);
}


void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
		if (!AForm::GetStatus())
			throw AForm::NotSigned();
		if (executor.getGrade() > AForm::getGte())
			throw AForm::GradeTooLowException();
		if (std::rand() % 2)
			std::cout << _target << " has been robotomized\n";
		else
			std::cout << "The robotomy of "	<< _target << " failed\n"; 	
}