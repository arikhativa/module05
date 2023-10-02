/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:11:33 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/02 11:11:35 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/
Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	:	_name(name), 
		_is_signed(false),
		_grade_to_sign(gradeToSign),
		_grade_to_execute(gradeToExecute)
{
	_checkGrade(_grade_to_sign);
	_checkGrade(_grade_to_execute);
}

Form::Form()
	:	_name("default"), 
		_is_signed(false),
		_grade_to_sign(150),
		_grade_to_execute(150)
{
}

Form::Form( const Form & src )
	:	_name(src._name), 
		_is_signed(src._is_signed),
		_grade_to_sign(src._grade_to_sign),
		_grade_to_execute(src._grade_to_execute)
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
		<< "signed: " << i.isSigned() << ", " 
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
	if (bureaucrat.getGrade() > _grade_to_sign)
		throw GradeTooLowException();
	_is_signed = true;
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

bool					Form::isSigned(void) const
{
	return _is_signed;
}

int					Form::getGradeToSign(void) const
{
	return _grade_to_sign;
}

int					Form::getGradeToExecute(void) const
{
	return _grade_to_execute;
}


/* ************************************************************************** */
