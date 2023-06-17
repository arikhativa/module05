/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:33:53 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/17 10:44:02 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute, const std::string &target)
	:	_name(name), 
		_signed(false),
		_gradeToSign(gradeToSign),
		_gradeToExecute(gradeToExecute),
		_target(target)
{
	_checkGrade(_gradeToSign);
	_checkGrade(_gradeToExecute);
}

AForm::AForm()
	:	_name("default"), 
		_signed(false),
		_gradeToSign(150),
		_gradeToExecute(150)
{
}

AForm::AForm( const AForm & src )
	:	_name(src._name), 
		_signed(src._signed),
		_gradeToSign(src._gradeToSign),
		_gradeToExecute(src._gradeToExecute)
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	(void)rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o << "AForm \"" << i.getName() << "\" [ "
		<< "signed: " << i.getSigned() << ", " 
		<< "grade to sign: " << i.getGradeToSign() << ", "
		<< "grade to execute: " << i.getGradeToExecute() << " ]";
	return o;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void				AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

void	AForm::_canExecForm(const Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (!getSigned())
		throw FormNotSignedException();
}

void	AForm::_checkGrade(int grade) const
{
	if (grade < _MAX_GRADE)
		throw GradeTooHighException();
	else if (grade > _MIN_GRADE)
		throw GradeTooLowException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


const std::string	&AForm::getTarget(void) const
{
	return _target;
}

const std::string	&AForm::getName(void) const
{
	return _name;
}

bool					AForm::getSigned(void) const
{
	return _signed;
}

int					AForm::getGradeToSign(void) const
{
	return _gradeToSign;
}

int					AForm::getGradeToExecute(void) const
{
	return _gradeToExecute;
}


/* ************************************************************************** */