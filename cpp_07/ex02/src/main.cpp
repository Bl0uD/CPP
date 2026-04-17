/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 15:12:19 by jdupuis           #+#    #+#             */
/*   Updated: 2026/04/17 11:43:00 by jdupuis          ###   ########.fr       */
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
    if (empty.size() != 0)
    {
        std::cerr << "Empty array should have size 0" << std::endl;
        return ( 1 );
    }
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
    Array<int> copy(numbers);
    Array<int> assigned;
    assigned = numbers;
    copy[0] = -12345;
    assigned[1] = -54321;
    if (numbers[0] == copy[0] || numbers[1] == assigned[1])
    {
        std::cerr << "Copy is not independent from source" << std::endl;
        delete [] mirror;
        return ( 1 );
    }
    std::cout << "Deep copy successful" << std::endl << std::endl;

    std::cout << "=== Test 4: Verify data integrity after copy ===" << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            delete [] mirror;
            return ( 1 );
        }
    }
    std::cout << "All values match!" << std::endl << std::endl;

    std::cout << "=== Test 5: Out of bounds exceptions ===" << std::endl;
    const Array<int>& constNumbers = numbers;
    try
    {
        numbers[-2] = 0;
        std::cerr << "Negative index did not throw" << std::endl;
        delete [] mirror;
        return ( 1 );
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught for negative index: " << e.what() << std::endl;
    }
    try
    {
        static_cast<void>(constNumbers[MAX_VAL]);
        std::cerr << "Const out-of-range index did not throw" << std::endl;
        delete [] mirror;
        return ( 1 );
    }
    catch(const std::exception& e)
    {
        std::cout << "Exception caught for index >= size: " << e.what() << std::endl;
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
    if (strings.size() != 3)
    {
        std::cerr << "String array size mismatch" << std::endl;
        return ( 1 );
    }
    std::cout << "Strings: " << strings[0] << " " << strings[1] << " " << strings[2] << std::endl;

    std::cout << "\n=== All tests passed! ===" << std::endl;
    return ( 0 );
}