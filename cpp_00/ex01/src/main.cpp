/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:12:35 by jdupuis           #+#    #+#             */
/*   Updated: 2025/09/30 17:27:17 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/PhoneBook_class.hpp"

int main(void)
{
	Phonebook	phonebook;
	std::string	input;

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
