/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrabby <yrabby@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:44:16 by yrabby            #+#    #+#             */
/*   Updated: 2023/06/15 12:21:05 by yrabby           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <unistd.h>
# include <cstdlib>
# include <ctime>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{

	public:
		RobotomyRequestForm();
		virtual ~RobotomyRequestForm();

		virtual void		execute(Bureaucrat const & executor) const;

	private:
		RobotomyRequestForm( RobotomyRequestForm const & src );
		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

};

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */