#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	
	private :
		std::string _target;
	public :
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		std::string getTar()const;
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		void execute(Bureaucrat const & executor) const;
};