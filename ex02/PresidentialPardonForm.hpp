#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm
{
	
	private :
		std::string _target;
	public :
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm& other);
		std::string getTar()const;
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		void execute(Bureaucrat const & executor) const;
};