/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:12:45 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/05 11:53:20 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main( void )
{
	try
	{
		Bureaucrat charlie("Charlie", 0);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Bureaucrat diana("Diana", 151);
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Bureaucrat alice("Alice", 12);
		std::cout << alice << std::endl;
		alice.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Bureaucrat bob("Bob", 150);
		bob.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;
	try
	{
		Bureaucrat eve("Eve", 5);
		eve.incrementGrade();
		eve.incrementGrade();
		eve.incrementGrade();
		eve.incrementGrade();
		eve.incrementGrade();
		eve.incrementGrade();
		eve.incrementGrade();
		eve.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return ( 0 );
}
