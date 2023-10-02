/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:29:00 by yrabby            #+#    #+#             */
/*   Updated: 2023/10/02 11:28:22 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#include "AForm.hpp"

class AForm;

class Bureaucrat
{
public:
	explicit Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();

	const std::string &getName(void) const;
	int getGrade(void) const;
	void incrementGrade(void);
	void decrementGrade(void);
	void signForm(AForm &form) const;
	void executeForm(AForm const &form) const;

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
	Bureaucrat &operator=(Bureaucrat const &rhs);
	Bureaucrat(Bureaucrat const &src);
	void _checkGrade(int grade) const;

	static const int _MAX_GRADE = 1;
	static const int _MIN_GRADE = 150;

	const std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif /* ****************************************************** BUREAUCRAT_H */
