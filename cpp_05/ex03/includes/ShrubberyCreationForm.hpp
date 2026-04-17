/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:02:00 by jdupuis           #+#    #+#             */
/*   Updated: 2026/04/17 11:01:14 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFROM_HPP
# define SHRUBBERYCREATIONFROM_HPP

# include "AForm.hpp"
# include <fstream>
# include <iostream>
# include <string>

class Bureaucrat;

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;

	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const &instance );
		ShrubberyCreationForm &operator=( ShrubberyCreationForm const &instance );
		
		std::string getTarget() const;
		
		void execute( Bureaucrat const &instance ) const;
};

std::ostream &operator<<( std::ostream &ostream, const ShrubberyCreationForm &instance );

#endif