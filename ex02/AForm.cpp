/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:33:53 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/02 11:28:12 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute, const std::string &target)
	: _name(name),
	  _is_signed(false),
	  _grade_to_sign(gradeToSign),
	  _grade_to_execute(gradeToExecute),
	  _target(target)
{
	_checkGrade(_grade_to_sign);
	_checkGrade(_grade_to_execute);
}

AForm::AForm()
	: _name("default"),
	  _is_signed(false),
	  _grade_to_sign(150),
	  _grade_to_execute(150)
{
}

AForm::AForm(const AForm &src)
	: _name(src._name),
	  _is_signed(src._is_signed),
	  _grade_to_sign(src._grade_to_sign),
	  _grade_to_execute(src._grade_to_execute)
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

AForm &AForm::operator=(AForm const &rhs)
{
	(void)rhs;
	return *this;
}

std::ostream &operator<<(std::ostream &o, AForm const &i)
{
	o << "AForm \"" << i.getName() << "\" [ "
	  << "signed: " << i.isSigned() << ", "
	  << "grade to sign: " << i.getGradeToSign() << ", "
	  << "grade to execute: " << i.getGradeToExecute() << " ]";
	return o;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _grade_to_sign)
		throw GradeTooLowException();
	_is_signed = true;
}

void AForm::_canExecForm(const Bureaucrat &bureaucrat) const
{
	if (bureaucrat.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (!isSigned())
		throw FormNotSignedException();
}

void AForm::_checkGrade(int grade) const
{
	if (grade < _MAX_GRADE)
		throw GradeTooHighException();
	else if (grade > _MIN_GRADE)
		throw GradeTooLowException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string &AForm::getTarget(void) const
{
	return _target;
}

const std::string &AForm::getName(void) const
{
	return _name;
}

bool AForm::isSigned(void) const
{
	return _is_signed;
}

int AForm::getGradeToSign(void) const
{
	return _grade_to_sign;
}

int AForm::getGradeToExecute(void) const
{
	return _grade_to_execute;
}

/* ************************************************************************** */
