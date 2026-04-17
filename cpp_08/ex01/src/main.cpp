/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:31:16 by cgodecke          #+#    #+#             */
/*   Updated: 2026/04/17 11:51:38 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Span.hpp"
#include <cstdlib>
#include <ctime>
#include <list>

int main()
{
	std::cout << "\033[33m" << "Test vector container\n"<< "\033[0m";
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	try
	{
		sp.addNumber(11);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\033[33m" << "Test list range\n"<< "\033[0m";
	Span sp2 = Span(100);
	std::list<int> v;
	std::srand(time(NULL));
	for ( int i = 0; i < 100; i++ )
	{
		int random_int = rand() % 1000000;
		v.push_back(random_int);
	}
	try
	{
		sp2.addMultipleNumbers( v.begin(), v.end() );
		std::cout << "shortest span: " << sp2.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp2.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\033[33m" << "Test vector large range\n"<< "\033[0m";
	Span sp3 = Span(10000);
	std::vector<int> v2;
	std::srand(time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		
		int random_int = rand() % 1000000000;
		v2.push_back(random_int);
	}
	try
	{
		sp3.addMultipleNumbers(v2.begin(), v2.end());
		std::cout << "shortest span: " << sp3.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp3.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\033[33m" << "Test span exceptions\n"<< "\033[0m";
	Span sp4 = Span(1);
	try
	{
		std::cout << sp4.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::vector<int> tiny;
		tiny.push_back(1);
		tiny.push_back(2);
		sp4.addMultipleNumbers(tiny.begin(), tiny.end());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}