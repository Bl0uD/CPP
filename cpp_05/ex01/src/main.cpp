/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:12:45 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/05 12:19:24 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int main(void)
{
	std::cout << "Creating Bureaucrat 'John' with grade 149..." << std::endl;
	Bureaucrat john("John", 149);

	std::cout << std::endl << "Attempting to decrement 'John's grade..." << std::endl;
	try
	{
		john.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "Creating Form 'Form1' with invalid grades (151, 130)..." << std::endl;
	try
	{
		Form form1("Form1", 151, 130);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "Creating Form 'Form2' with valid grades (3, 12)..." << std::endl;
	try
	{
		Form form2("Form2", 3, 12);
		std::cout << "Form created: " << form2 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "Creating Bureaucrat 'Jane' with grade 3..." << std::endl;
	Bureaucrat jane("Jane", 3);

	std::cout << std::endl << "Attempting to sign 'Form3' with 'Jane'..." << std::endl;
	try
	{
		Form form3("Form3", 3, 12);
		form3.beSigned(jane);
		std::cout << "Form signed: " << form3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "Creating Bureaucrat 'Alice' with grade 2..." << std::endl;
	Bureaucrat alice("Alice", 2);

	std::cout << std::endl << "Attempting to sign 'Form4' with 'Alice' using signForm..." << std::endl;
	try
	{
		Form form4("Form4", 1, 12);
		alice.signForm(form4);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
