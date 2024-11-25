#include "ShrubberyCreationForm.hpp"
#include <ostream>
#include <fstream>
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "A ShrubberyCreationForm with target : " << _target << " has been created\n";
}

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = "default";
	std::cout << "A ShrubberyCreationForm with target : " << _target << " has been created\n";
}


std::string ShrubberyCreationForm::getTar()const
{
	return _target;
}


ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = other.getTar();
	std::cout << "A ShrubberyCreationForm with target : " << _target << " has been copied\n";
}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	if (this != &other)
	{
		_target = other.getTar();
	}
	return (*this);
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{

		if (!AForm::GetStatus())
			throw AForm::NotSigned();
		if (executor.getGrade() > AForm::getGte())
			throw AForm::GradeTooLowException();
		std::cout << executor.getName() << " execute " << AForm::GetName() << std::endl;
		std::ofstream ofile;
		std::string o = _target ;
		ofile.open( (_target + "_shrubbery").c_str());
  		ofile << "                                  # #### ####" << std::endl;
  		ofile << "                                ### \\/#|### |/####" << std::endl;
  		ofile << "                               ##\\/#/ \\\\||/##/_/##/_#" << std::endl;
  		ofile << "                             ###  \\/###|/ \\/ # ###" << std::endl;
  		ofile << "                           ##_\\_#\\_\\## | #/###_/_####" << std::endl;
  		ofile << "                          ## #### # \\ #| /  #### ##/##" << std::endl;
  		ofile << "                           __#_--###`  |{,###---###-~" << std::endl;
  		ofile << "                                     \\ }{" << std::endl;
  		ofile << "                                      }}{" << std::endl;
  		ofile << "                                      }}{" << std::endl;
  		ofile << "                                      {{}}" << std::endl;
  		ofile << "                                , -=-~{ .-^- _" << std::endl;
  		ofile << "                                      `}" << std::endl;
  		ofile << "                                       {" << std::endl;
  		ofile.close();
	
	// catch (AForm::GradeTooLowException& e)
	// {
	// 	std::cout << executor.getName() << " with grade " << executor.getGrade() <<" can't execute this contract " << e.what() << std::endl;
	// }
	// catch (AForm::NotSigned& e)
	// {
	// 	std::cout << executor.getName() << " with grade " << executor.getGrade() <<" can't execute this contract " << e.what() << std::endl;
	// }
}