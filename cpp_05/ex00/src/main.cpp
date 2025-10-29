/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:12:45 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/29 13:51:21 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int	main( void )
{
	try {
		Bureaucrat alice("Alice", 1);
		// std::cout << alice << std::endl; // in case you want to test "<<"
		alice.incrementGrade();				// Should throw an exception
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n";
	try {
		Bureaucrat bob("Bob", 150);
		bob.decrementGrade();				// Should throw an exception
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat charlie("Charlie", 0);	// Should throw an exception
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n";
	try {
		Bureaucrat diana("Diana", 151);		// Should throw an exception
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n";
	try {
		Bureaucrat eve("Eve", 5);
		eve.incrementGrade();				// 4
		eve.incrementGrade();				// 3
		eve.incrementGrade();				// 2
		eve.incrementGrade();				// 1
		eve.incrementGrade();				// will throw error here. and stop try process.
		eve.incrementGrade();
		eve.incrementGrade();
		eve.decrementGrade();
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return ( 0 );
}
