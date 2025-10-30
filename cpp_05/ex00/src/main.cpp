/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:12:45 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/30 13:33:09 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main( void )
{
	try
	{
		Bureaucrat alice("Alice", 12);
		std::cout << alice << std::endl;
		alice.incrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Bureaucrat bob("Bob", 150);
		bob.decrementGrade();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat charlie("Charlie", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	try
	{
		Bureaucrat diana("Diana", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
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
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return ( 0 );
}
