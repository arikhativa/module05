/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 09:33:49 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/17 10:56:22 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

# include "Bureaucrat.hpp"

class Bureaucrat;
// TODO make sure all vars are in this case: grade_to_sign and not gradeToSign in all execs

class AForm
{
	public:
		explicit AForm(const std::string &name, int grade_to_sign, int grade_to_execute, const std::string &target);
		virtual ~AForm();

		const std::string	&getTarget(void) const;
		const std::string	&getName(void) const;
		bool				getSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		void				beSigned(const Bureaucrat &bureaucrat);
		virtual void		execute(Bureaucrat const & executor) const = 0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

	protected:
		void	_checkGrade(int grade) const;
		void	_canExecForm(const Bureaucrat &bureaucrat) const;

	private:
		AForm();
		AForm( AForm const & src );
		AForm &		operator=( AForm const & rhs );

		static const int	_MAX_GRADE = 1;
		static const int	_MIN_GRADE = 150;

		const std::string	_name;
		bool				_signed;
		const int			_grade_to_sign;
		const int			_grade_to_execute;
		const std::string	_target;


};

std::ostream &			operator<<( std::ostream & o, AForm const & i );

#endif /* ************************************************************ FORM_H */