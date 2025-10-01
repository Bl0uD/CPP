/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:48:28 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/01 15:46:53 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <string>
#include "../includes/Contact_class.hpp"

Contact::Contact( void )
{
	this->id = -1;
	return ;
}

Contact::~Contact( void )
{
	return ;
}

int	only_whitespace( std::string str )
{
	int	i = 0;
	
	while (i < (int)str.length())
	{
		if (!is_whitespace(str[i]))
        	return (0);
		i++;
	}
	return (1);
}

int	is_whitespace( char c )
{
	if (c == ' ' || c == '\t' || c == '\f'
		|| c == '\n' || c == '\r' || c == '\v')
		return (1);
	return (0);
}

std::string	clear_string( std::string str )
{
	std::string result;
	size_t		i = 0;

	while (i < str.length())
	{
		if (str[i] >= 32 && str[i] <= 126)
			result += str[i];
		else if (str[i] == ' ' || str[i] == '\t')
			result += ' ';
		i++;
	}
	while (!result.empty() && result[0] == ' ')
		result.erase(0, 1);

	while (!result.empty() && result[result.length() - 1] == ' ')
		result.erase(result.length() - 1);

return (result);
}

void	Contact::get_infos( void )
{
	std::cout << "What's your first name ?" << std::endl;
	do {
		std::getline(std::cin, this->first_name);
		this->first_name = clear_string(this->first_name);
		if (this->first_name.empty())
			std::cout << "Please enter a valid first name: ";
	} while (this->first_name.empty());

	std::cout << "What's your last name ?" << std::endl;
	do {
		std::getline(std::cin, this->last_name);
		this->last_name = clear_string(this->last_name);
		if (this->last_name.empty())
			std::cout << "Please enter a valid last name: ";
	} while (this->last_name.empty());

	std::cout << "What's your nickname ?" << std::endl;
	do {
		std::getline(std::cin, this->nickname);
		this->nickname = clear_string(this->nickname);
		if (this->nickname.empty())
			std::cout << "Please enter a valid nickname: ";
	} while (this->nickname.empty());

	std::cout << "What's your phone number ?" << std::endl;
	do {
		std::getline(std::cin, this->phone_number);
		this->phone_number = clear_string(this->phone_number);
		if (this->phone_number.empty())
			std::cout << "Please enter a valid phone number: ";
	} while (this->phone_number.empty());

	std::cout << "What's your darkest secret ?" << std::endl;
	do {
		std::getline(std::cin, this->darkest_secret);
		this->darkest_secret = clear_string(this->darkest_secret);
		if (this->darkest_secret.empty())
			std::cout << "Please enter a valid secret: ";
	} while (this->darkest_secret.empty());
}
