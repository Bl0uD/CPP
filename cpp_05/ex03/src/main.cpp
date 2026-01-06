/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:12:45 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/06 16:47:26 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main( void )
{
	try
	{
		Bureaucrat Big_Bob_Moustache("Big_Bob_Moustache", 10);
		Intern		internStan;
		AForm 		*rrf;

		rrf = internStan.makeForm("robotomy request", "Robocop_case");
		Big_Bob_Moustache.signForm(*rrf);
		rrf->execute(Big_Bob_Moustache);

		delete rrf;
	}
	catch ( const std::exception &e )
	{
		std::cout << e.what() << std::endl;
	}
	return ( 0 );
}
