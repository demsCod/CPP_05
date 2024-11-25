#include "Intern.hpp"


AForm *s(std::string& target){
	return new ShrubberyCreationForm(target);
}

AForm *p(std::string& target){
	return new PresidentialPardonForm(target);
}

AForm *r(std::string& target){
	return new RobotomyRequestForm(target);
}




AForm *Intern::makeForm(std::string name, std::string target)
{
	try
	{
		std::string tab[3] = {"robotomy request", "presidential pardon", "shruberry creation"};
		AForm *(*tab_ptr[3])(std::string& target) = {r, p, s};
		int i = 0;
		while(tab[i] != name && i < 3)
			i++;
		switch (i)
		{
			case 0 :
				 return ((*tab_ptr[i])(target));
				 break;
			case 1 :
				 return ((*tab_ptr[i])(target));
				 break;
			case 2 :
				 return ((*tab_ptr[i])(target));
				 
				 break;
			
			default :
				throw Intern::InvalidNameException();
				break;
		}
	}
	catch(Intern::InvalidNameException& e)
	{
		std::cout << e.what() << " " << name << '\n';
		return NULL;
	}
}