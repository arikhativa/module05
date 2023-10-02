/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:45:46 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/02 11:52:01 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void Shrubbery()
{
	{
		Bureaucrat b1("Bob[1]", 1);
		Bureaucrat b2("Yoni[150]", 150);
		Bureaucrat b3("Oded[145]", 145);
		ShrubberyCreationForm f1("home");

		std::cout << f1 << std::endl;

		b1.executeForm(f1);
		std::cout << b1 << std::endl;
		b1.signForm(f1);
		b1.executeForm(f1);

		std::cout << b2 << std::endl;
		b2.signForm(f1);
		b2.executeForm(f1);

		std::cout << b3 << std::endl;
		b3.signForm(f1);
		b3.executeForm(f1);
	}
}

void Robotomy()
{
	{
		Bureaucrat b1("Bob[1]", 1);
		RobotomyRequestForm f1("Jack");

		std::cout << f1 << std::endl;
		std::cout << b1 << std::endl;
		b1.signForm(f1);
		b1.executeForm(f1);
		{
			Bureaucrat b2("Yoni[73]", 73);
			Bureaucrat b3("Oded[72]", 72);
			b2.signForm(f1);
			b2.executeForm(f1);
			b3.signForm(f1);
			b3.executeForm(f1);
		}
	}
}

void President()
{
	{
		Bureaucrat b1("Bob[1]", 1);
		PresidentialPardonForm f1("Mordi");

		std::cout << f1 << std::endl;
		std::cout << b1 << std::endl;
		b1.signForm(f1);
		b1.executeForm(f1);
	}
}

int main(void)
{
	// Shrubbery();
	Robotomy();
	President();
	return 0;
}
