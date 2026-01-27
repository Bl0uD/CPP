/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 00:41:42 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/27 15:36:06 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

template <typename T>
void randomMultiplier(T const &i)
{
	int randomPrefix = (rand() % 100) + 15; // Generate a random number between 15 and 114.
	std::cout << i << " * " << randomPrefix << " = " << i * randomPrefix << std::endl;
}

template <typename T>
void doubleInt(T &i)
{
	i = i * 2;
	std::cout << "Response value doubled: " << i << std::endl;
}

template <typename T>
void printInt(T const &toPrint)
{
	std::cout << toPrint << " ";
}

int main()
{
	int const only_read_array[] = {2222, 44444, 6666, 88888, 11111111};			// We can read and not modify because is "const"
	int intArray[] = {20, 40, 60, 80, 100};										// We can modify it

	std::cout << "=== Status array ===" << std::endl;
	std::cout << "Only read array : ";	
	iter(only_read_array, 5, printInt<int>);

	std::cout << "\nArray that will get changed : ";	
	iter(intArray, 5, printInt<int>);
	std::cout << "\n";

	std::cout << "\n=== Testing with const reference function ===" << std::endl;
	iter(intArray, 5, randomMultiplier<int>);

	std::cout << "\n=== Status array ===" << std::endl;
	iter(intArray, 5, printInt<int>);
	std::cout << "\n";

	std::cout << "\n=== Testing with non-const reference function ===" << std::endl;
	iter(intArray, 5, doubleInt<int>);

	std::cout << "\n=== Status array ===" << std::endl;
	iter(intArray, 5, printInt<int>);

	std::cout << std::endl;
	return ( 0 );
}