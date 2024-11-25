#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm
{
	
	private :
		std::string _target;
	public :
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		std::string getTar()const;
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

		void execute(Bureaucrat const & executor) const;
};

#endif