/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:45:46 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/02 12:26:55 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void subject()
{
	{
		Intern someRandomIntern;
		AForm *rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		Bureaucrat b("Berger", 1);
		b.signForm(*rrf);
		rrf->execute(b);

		delete rrf;
	}
}

void intern()
{
	{
		Intern i;
		AForm *f1;

		f1 = i.makeForm(Intern::PRESIDENTIAL_PARDON, "yoyo");
		std::cout << *f1 << std::endl;
		delete f1;
		f1 = i.makeForm(Intern::ROBOTOMY_REQUEST, "mimi");
		std::cout << *f1 << std::endl;
		delete f1;
		f1 = i.makeForm(Intern::SHRUBBERY_CREATION, "lulu");
		std::cout << *f1 << std::endl;
		delete f1;

		std::cout << std::endl
				  << "\t - Test: Wrong form name" << std::endl;

		f1 = i.makeForm("asd", "lulu");
		if (!f1)
			std::cout << "returned NULL" << std::endl;
	}
}

int main(void)
{
	subject();
	intern();
	return 0;
}
