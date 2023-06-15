/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 10:57:51 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/15 10:59:04 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{

	public:
		ShrubberyCreationForm();
		virtual ~ShrubberyCreationForm();
		virtual void		execute(Bureaucrat const & executor) const;

	private:
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );

};

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */