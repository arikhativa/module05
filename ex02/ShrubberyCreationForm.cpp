#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm()
	:	AForm("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src )
	:	AForm("ShrubberyCreationForm", 145, 137)
{
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	AForm const *a = &i;
	o << a;
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void		ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	_canExecForm(executor);

}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */