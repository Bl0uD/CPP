/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:12:35 by jdupuis           #+#    #+#             */
/*   Updated: 2025/09/29 18:00:16 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook_class.hpp"

int main(void)
{
	Phonebook contact;
	
	std::string	input;

	std::cin >> input;
	while (input.compare("ADD") && input.compare("SEARCH") && input.compare("EXIT"))
		std::cin >> input;
	/*if (!input.compare("ADD"))
		add();
	if (!input.compare("SEARCH"))
		search();
	if (!input.compare("EXIT"))
		return (0);*/
	return (0);
}
