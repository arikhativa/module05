/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:45:46 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/14 15:38:55 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void	simple()
{
	Bureaucrat	b1("Bob", 1);
	Form		f1("c137", 1, 1);

	std::cout << b1 << ", is working with " << f1 << std::endl;

	b1.signForm(f1);
	b1.decrementGrade();
	std::cout << b1 << ", lost some grade " << std::endl;
	std::cout << b1 << ", is working with " << f1 << std::endl;
	b1.signForm(f1);
}

void	except()
{
	try
	{
		Form		f1("except", 0, 1);
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form b1("151", 1, 151);
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int main( void )
{
	simple();
	except();
	return 0;
}
