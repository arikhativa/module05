/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:29:00 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/02 11:33:09 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

class Bureaucrat
{
public:
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();

	const std::string &getName(void) const;
	int getGrade(void) const;

	void signForm(Form &form) const;

	void incrementGrade(void);
	void decrementGrade(void);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	Bureaucrat();
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &rhs);

	void _checkGrade(int grade) const;

	static const int _MAX_GRADE = 1;
	static const int _MIN_GRADE = 150;

	const std::string _name;
	int _grade;
};

#include "Form.hpp"

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif /* ****************************************************** BUREAUCRAT_H */
