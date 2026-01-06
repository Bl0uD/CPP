/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:03:18 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/06 14:36:15 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		~PresidentialPardonForm();
		PresidentialPardonForm();
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm const &instance );
		PresidentialPardonForm &operator=( PresidentialPardonForm const &instance );
		
		std::string getTarget() const;
		
		void execute( Bureaucrat const &instance ) const;
};

std::ostream &operator<<( std::ostream &ostream, const PresidentialPardonForm &instance );

#endif