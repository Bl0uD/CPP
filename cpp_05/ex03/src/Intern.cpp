/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:56:24 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/06 16:50:49 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::~Intern(){}

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern( Intern const &copy )
{
	*this = copy;
}

Intern &Intern::operator=( Intern const &instance )
{
	(void)instance;
	return ( *this );
}

AForm	*presidential_pardon( std::string target )
{
	AForm *form = new PresidentialPardonForm ( target );
	return ( form );
}

AForm	*robotomy_request( std::string target )
{
	AForm *form = new RobotomyRequestForm ( target );
	return ( form );
}

AForm	*shrubbery_creation( std::string target )
{
	AForm *form = new ShrubberyCreationForm ( target );
	return ( form );
}

AForm *Intern::makeForm( std::string formName, std::string target )
{
	std::string formNames[3] = { "presidential pardon", "robotomy request", "shrubbery creation" };
	AForm	*( *pFunction[3] )( std::string ) = { presidential_pardon, robotomy_request, shrubbery_creation };
	int i = 0;
	while (i < 3 && formName != formNames[i])
		i++;
	
	if (i < 3)
	{
		std::cout << "Intern creates " << formName << std::endl;
		return ((*pFunction[i])( target ));
	}
	std::cout << "Form name \"" << formName << "\" doesn't exist" << std::endl;
	throw AForm::InexistantFormName();
}
