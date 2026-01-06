/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:12:45 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/06 15:23:32 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

int main( void )
{

	std::cout << "=== Testing ShrubberyCreationForm ===" << std::endl;
	try
	{
		Bureaucrat john( "John", 3 );
		ShrubberyCreationForm shrubbery( "Garden" );

		std::cout << "Signing ShrubberyCreationForm..." << std::endl;
		john.signForm( shrubbery );

		std::cout << "Executing ShrubberyCreationForm..." << std::endl;
		john.executeForm( shrubbery );
	}
	catch ( std::exception &e )
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n\n\n=== Testing RobotomyRequestForm ===" << std::endl;
	try
	{
		Bureaucrat jane( "Jane", 45 );
		RobotomyRequestForm robotomy( "Robot" );

		std::cout << "Signing RobotomyRequestForm..." << std::endl;
		jane.signForm( robotomy );

		std::cout << "Executing RobotomyRequestForm..." << std::endl;
		jane.executeForm( robotomy );
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n\n\n=== Testing PresidentialPardonForm ===" << std::endl;
	try
	{
		Bureaucrat alice( "Alice", 28 );
		PresidentialPardonForm pardon( "Bob" );

		std::cout << "Signing PresidentialPardonForm..." << std::endl;
		alice.signForm( pardon );

		std::cout << "Executing PresidentialPardonForm..." << std::endl;
		alice.executeForm( pardon );
	}
	catch ( std::exception &e )
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}


	// * Testing Errors: 
	std::cout << "\n\n\n=== Testing Invalid Cases ===" << std::endl;
	try
	{
		Bureaucrat lowRank( "LowRank", 150 );
		ShrubberyCreationForm invalidForm( "InvalidGarden" );

		std::cout << "Attempting to sign with insufficient grade..." << std::endl;
		lowRank.signForm( invalidForm );
	}
	catch ( std::exception &e )
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat lowRank( "normal", 144 );
		ShrubberyCreationForm invalidForm( "TestGarden" );

		std::cout << "Attempting to sign with insufficient grade..." << std::endl;
		lowRank.signForm( invalidForm );
	}
	catch ( std::exception &e )
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat highRank( "HighRank", 1 );
		RobotomyRequestForm unsignedForm( "UnsignedRobot" );

		std::cout << "Attempting to execute an unsigned form..." << std::endl;
		highRank.executeForm( unsignedForm );
	}
	catch ( std::exception &e )
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return ( 0 );
}
