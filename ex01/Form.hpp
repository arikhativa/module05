#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		explicit Form(const std::string &name, int gradeToSign, int gradeToExecute);
		~Form();

		const std::string	&getName(void) const;
		bool				getSigned(void) const;
		int					getGradeToSign(void) const;
		int					getGradeToExecute(void) const;
		void				beSigned(const Bureaucrat &bureaucrat);

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

	private:
		Form();
		Form( Form const & src );
		Form &		operator=( Form const & rhs );

		static const int	_MAX_GRADE = 1;
		static const int	_MIN_GRADE = 150;

		const std::string	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;

		void	_checkGrade(int grade) const;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */
