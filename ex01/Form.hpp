/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 11:11:13 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/02 11:35:12 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
public:
	Form(const std::string &name, int grade_to_sign, int grade_to_execute);
	~Form();

	const std::string &getName(void) const;
	bool isSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;

	void beSigned(const Bureaucrat &bureaucrat);

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
	Form();
	Form(Form const &src);
	Form &operator=(Form const &rhs);

	static const int _MAX_GRADE = 1;
	static const int _MIN_GRADE = 150;

	const std::string _name;
	bool _is_signed;
	const int _grade_to_sign;
	const int _grade_to_execute;

	void _checkGrade(int grade) const;
};

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif /* ************************************************************ FORM_H */
