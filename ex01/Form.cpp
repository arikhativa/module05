#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	:	_name(name), 
		_signed(false),
		_gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute)
{
	_checkGrade(_gradeToSign);
	_checkGrade(_gradeToExecute);
}

Form::Form()
	:	_name("default"), 
		_signed(false),
		_gradeToSign(150),
		_gradeToExecute(150)
{
}

Form::Form( const Form & src )
	:	_name(src._name), 
		_signed(src._signed),
		_gradeToSign(src._gradeToSign),
		_gradeToExecute(src._gradeToExecute)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "Form \"" << i.getName() << "\" [ "
		<< "signed: " << i.getSigned() << ", " 
		<< "grade to sign: " << i.getGradeToSign() << ", "
		<< "grade to execute: " << i.getGradeToExecute() << " ]";
	return o;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void				Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

void	Form::_checkGrade(int grade) const
{
	if (grade < _MAX_GRADE)
		throw GradeTooHighException();
	else if (grade > _MIN_GRADE)
		throw GradeTooLowException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


const std::string	&Form::getName(void) const
{
	return _name;
}

bool					Form::getSigned(void) const
{
	return _signed;
}

int					Form::getGradeToSign(void) const
{
	return _gradeToSign;
}

int					Form::getGradeToExecute(void) const
{
	return _gradeToExecute;
}


/* ************************************************************************** */
