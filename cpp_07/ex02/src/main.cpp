/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:12:19 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/12 15:20:15 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../includes/Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	std::cout << "=== Test 1: Default constructor ===" << std::endl;
	Array<int> empty;
	std::cout << "Empty array created successfully" << std::endl << std::endl;

	std::cout << "=== Test 2: Constructor with parameter and [] operator ===" << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "Array filled with random values" << std::endl << std::endl;

    std::cout << "=== Test 3: Copy constructor and assignment operator ===" << std::endl;
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "Deep copy successful (tmp and test created)" << std::endl;
    }
    std::cout << "tmp and test destroyed (out of scope)" << std::endl << std::endl;

    std::cout << "=== Test 4: Verify data integrity after copy ===" << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "All values match!" << std::endl << std::endl;

    std::cout << "=== Test 5: Out of bounds exceptions ===" << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught for negative index: " << e.what() << std::endl;
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception caught for index >= size: " << e.what() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;

    std::cout << "\n=== Test 6: Array with different types (strings) ===" << std::endl;
    Array<std::string> strings(3);
    strings[0] = "Hello";
    strings[1] = "World";
    strings[2] = "!";
    std::cout << "Strings: " << strings[0] << " " << strings[1] << " " << strings[2] << std::endl;

    std::cout << "\n=== All tests passed! ===" << std::endl;
    return 0;
}