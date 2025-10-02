/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:48:28 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/02 16:53:11 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <limits>
#include <string>
#include "../includes/Contact_class.hpp"
#include "../includes/utils.hpp"

Contact::Contact( void )
{
	this->_id = -1;
	return ;
}

Contact::~Contact( void )
{
	return ;
}

std::string	Contact::get_First_name( void ) const
{
	return this->_first_name;
}

std::string	Contact::get_Last_name( void ) const
{
	return this->_last_name;
}

std::string	Contact::get_Nickname( void ) const
{
	return this->_nickname;
}

void	Contact::set_Id( int v )
{
	this->_id = v;
}

void	Contact::set_infos( void )
{
	std::cout << "What's your first name ?" << std::endl;
	do {
		std::getline(std::cin, this->_first_name);
		this->_first_name = clear_string(this->_first_name);
		if (this->_first_name.empty())
			std::cout << "Please enter a valid first name: ";
	} while (this->_first_name.empty());

	std::cout << "What's your last name ?" << std::endl;
	do {
		std::getline(std::cin, this->_last_name);
		this->_last_name = clear_string(this->_last_name);
		if (this->_last_name.empty())
			std::cout << "Please enter a valid last name: ";
	} while (this->_last_name.empty());

	std::cout << "What's your _nickname ?" << std::endl;
	do {
		std::getline(std::cin, this->_nickname);
		this->_nickname = clear_string(this->_nickname);
		if (this->_nickname.empty())
			std::cout << "Please enter a valid _nickname: ";
	} while (this->_nickname.empty());

	std::cout << "What's your phone number ?" << std::endl;
	do {
		std::getline(std::cin, this->_phone_number);
		this->_phone_number = clear_string(this->_phone_number);
		if (this->_phone_number.empty())
			std::cout << "Please enter a valid phone number: ";
	} while (this->_phone_number.empty());

	std::cout << "What's your darkest secret ?" << std::endl;
	do {
		std::getline(std::cin, this->_darkest_secret);
		this->_darkest_secret = clear_string(this->_darkest_secret);
		if (this->_darkest_secret.empty())
			std::cout << "Please enter a valid secret: ";
	} while (this->_darkest_secret.empty());
}
