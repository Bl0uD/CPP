/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:48:28 by jdupuis           #+#    #+#             */
/*   Updated: 2025/09/30 17:56:40 by jdupuis          ###   ########.fr       */
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

void	Contact::clear_infos( void )
{
	this->first_name.clear();
	this->last_name.clear();
	this->nickname.clear();
	this->phone_number.clear();
	this->darkest_secret.clear();
}

int	only_whitespace( std::string str )
{
	int	i = 0;
	
	while (i < (int)str.length())
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\f'
			&& str[i] != '\n' && str[i] != '\r' && str[i] != '\v')
        	return (0);
		i++;
	}
	return (1);
}

void	Contact::get_infos( void )
{
	clear_infos();
	
	std::cout << "What's your first name ?" << std::endl;
	while (this->first_name.empty() || only_whitespace(this->first_name))
		std::getline(std::cin, this->first_name);

	std::cout << "What's your last name ?" << std::endl;
	while (this->last_name.empty() || only_whitespace(this->last_name))
		std::getline(std::cin, this->last_name);

	std::cout << "What's your nicknamee ?" << std::endl;
	while (this->nickname.empty() || only_whitespace(this->nickname))
		std::getline(std::cin, this->nickname);

	std::cout << "What's your phone number ?" << std::endl;
	while (this->phone_number.empty() || only_whitespace(this->phone_number))
		std::getline(std::cin, this->phone_number);

	std::cout << "What's your darkest secret ?" << std::endl;
	while (this->darkest_secret.empty() || only_whitespace(this->darkest_secret))
		std::getline(std::cin, this->darkest_secret);
}
