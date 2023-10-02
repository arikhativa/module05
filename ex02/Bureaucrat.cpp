/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:06:36 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/02 11:30:53 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
	: _name(name), _grade(grade)
{
	_checkGrade(_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
	: _name(src._name), _grade(src._grade)
{
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
	catch (const AForm::FormNotSignedException &e)
	{
		std::cerr << _name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::incrementGrade(void)
{
	int tmp = _grade - 1;
	_checkGrade(tmp);
	_grade = tmp;
}

void Bureaucrat::decrementGrade(void)
{
	int tmp = _grade + 1;
	_checkGrade(tmp);
	_grade = tmp;
}

void Bureaucrat::_checkGrade(int grade) const
{
	if (grade < _MAX_GRADE)
		throw GradeTooHighException();
	else if (grade > _MIN_GRADE)
		throw GradeTooLowException();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

const std::string &Bureaucrat::getName(void) const
{
	return _name;
}

int Bureaucrat::getGrade(void) const
{
	return _grade;
}

/* ************************************************************************** */
