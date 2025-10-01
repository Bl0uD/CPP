/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:12:35 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/01 02:23:22 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/PhoneBook_class.hpp"

void	print_banner(void)
{
	std::cout << std::endl;
	std::cout << " ____  _   _  ___  _   _ _____ ____   ___   ___  _  __" << std::endl;
	std::cout << "|  _ \\| | | |/ _ \\| \\ | | ____| __ ) / _ \\ / _ \\| |/ /" << std::endl;
	std::cout << "| |_) | |_| | | | |  \\| |  _| |  _ \\| | | | | | | ' / " << std::endl;
	std::cout << "|  __/|  _  | |_| | |\\  | |___| |_) | |_| | |_| | . \\ " << std::endl;
	std::cout << "|_|   |_| |_|\\___/|_| \\_|_____|____/ \\___/ \\___/|_|\\_\\" << std::endl;
	std::cout << std::endl;
	std::cout << "Welcome to your personal phonebook!" << std::endl;
	std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	Phonebook	phonebook;
	std::string	input;

	print_banner();
	
	std::getline(std::cin, input);
	while (input.compare("EXIT"))
	{
		if (!input.compare("ADD"))
			phonebook.add();
		if (!input.compare("SEARCH"))
			phonebook.search();
		std::getline(std::cin, input);
	}
	return (0);
}
