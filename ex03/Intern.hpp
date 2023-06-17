/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:05:02 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/17 11:39:11 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern;

typedef AForm *(Intern::*form_create)(std::string const &);

class Intern
{
	public:
		Intern();
		~Intern();

		AForm	*makeForm(const std::string &form_name, const std::string &target);

		static const std::string	PRESIDENTIAL_PARDON;
		static const std::string	ROBOTOMY_REQUEST;
		static const std::string	SHRUBBERY_CREATION;

	private:
		Intern( Intern const & src );
		Intern &		operator=( Intern const & rhs );

		AForm	*_createPresidentialPardonForm(std::string const &target);
		AForm	*_createRobotomyRequestForm(std::string const &target);
		AForm	*_createShrubberyCreationForm(std::string const &target);

		static const int	_FORM_COUNT = 3;

		std::string	_form_names[_FORM_COUNT];
		form_create	_form_ctors[_FORM_COUNT];

};

#endif /* ********************************************************** INTERN_H */