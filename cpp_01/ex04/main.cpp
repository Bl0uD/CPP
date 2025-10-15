/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:26:41 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/15 16:12:44 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int	check_input(std::string filename, std::string s1, std::string s2)
{
	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cout << "Empty input(s)" << std::endl;
		return (0);
	}
	if (s1 == s2)
	{
		std::cout << "strings are the same" << std::endl;
		return (0);
	}
	return (1);
}

int	try_to_open(std::ifstream &inputFile, std::ofstream &outputFile)
{
	if (!inputFile.is_open())
	{
		std::cout << "Could not open inputed file" << std::endl;
		return (0);
	}
	if (!outputFile.is_open())
	{
		std::cout << "could not open output file." << std::endl;
		inputFile.close();
		return (0);
	}
	return (1);
}

int	main( int ac, char **av )
{
	std::string filename;
	std::string s1;
	std::string s2;
	
	if (ac != 4)
	{
		std::cout << "Error imput:" << std::endl;
		std::cout << "./Sed_is_for_losers [filename] [target string to chage] [string to replace with]" << std::endl;
		return (1);
	}

	filename = av[1];
	s1 = av[2];
	s2 = av[3];

	if (!check_input(filename, s1, s2))
		return (1);

	std::ifstream inputFile(filename.c_str());
	std::ofstream outputFile((filename + ".replace").c_str());

	if (!try_to_open(inputFile, outputFile))
		return (1);

	std::string line;
	std::size_t s1_length = s1.length();
	std::size_t i = 0;
	bool is_found = false;

	while (getline(inputFile, line))
	{
		i = 0;
		while((i = line.find(s1, i)) != std::string::npos)
		{
			line.erase(i, s1_length);
			line.insert(i, s2);
			i += s2.length();
			is_found = true;
		}

		outputFile << line << std::endl;
	}

	inputFile.close();

	if (!is_found)
	{
		outputFile.close();
		std::remove((filename + ".replace").c_str());
		std::cout << "not match in file" << std::endl;
		return (1);
	}
	
	outputFile.close();
	std::cout << "thanks for using replace dear" << std::endl;
	return (0);
}
