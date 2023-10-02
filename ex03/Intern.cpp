/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:30:52 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/02 12:17:34 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string Intern::PRESIDENTIAL_PARDON = "presidential pardon";
const std::string Intern::ROBOTOMY_REQUEST = "robotomy request";
const std::string Intern::SHRUBBERY_CREATION = "shrubbery creation";

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	_form_names[0] = PRESIDENTIAL_PARDON;
	_form_names[1] = ROBOTOMY_REQUEST;
	_form_names[2] = SHRUBBERY_CREATION;
	_form_ctors[0] = &Intern::_createPresidentialPardonForm;
	_form_ctors[1] = &Intern::_createRobotomyRequestForm;
	_form_ctors[2] = &Intern::_createShrubberyCreationForm;
}

Intern::Intern(const Intern &src)
{
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

AForm *Intern::makeForm(const std::string &form_name, const std::string &target)
{
	form_create f;

	for (int i = 0; i < _FORM_COUNT; i++)
	{
		if (form_name == _form_names[i])
		{
			std::cout << "Intern creates " << form_name << std::endl;
			f = _form_ctors[i];
			return (this->*f)(target);
		}
	}
	std::cerr << "Form '" << form_name << "' not found" << std::endl;
	return NULL;
}

AForm *Intern::_createPresidentialPardonForm(std::string const &target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::_createRobotomyRequestForm(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::_createShrubberyCreationForm(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
