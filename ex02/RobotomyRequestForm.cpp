/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:45:07 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/02 11:43:42 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45, target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
	: AForm("RobotomyRequestForm", 72, 45, "")
{
	(void)src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

static void clearDisplay(const std::string &s)
{
	for (unsigned int a = 0; a < (s.length() + 1); ++a)
		std::cout << "\b";
	std::cout << std::flush;
}

static void writeDisplay(const std::string &s)
{
	std::cout << s << std::flush;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	_canExecForm(executor);

	const std::string s1 = "Berrrrrr.  ";
	const std::string s2 = "Berrrrrr.. ";
	const std::string s3 = "Berrrrrr...";

	for (int i = 0; i < 3; ++i)
	{
		writeDisplay(s1);
		clearDisplay(s1);
		usleep(200000);
		writeDisplay(s2);
		clearDisplay(s2);
		usleep(200000);
		writeDisplay(s3);
		clearDisplay(s3);
		usleep(200000);
	}
	std::cout << std::endl;
	std::srand(std::time(NULL));
	int num = std::rand() % 2;
	if (num == 0)
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	else
		std::cout << "the robotomy failed" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
