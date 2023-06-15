/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:45:46 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/15 11:40:13 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	Shrubbery()
{
	{
		Bureaucrat	b1("Bob[1]", 1);
		Bureaucrat	b2("Yoni[150]", 150);
		Bureaucrat	b3("Oded[145]", 145);
		ShrubberyCreationForm f1;

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

int main( void )
{
	Shrubbery();
	return 0;
}
