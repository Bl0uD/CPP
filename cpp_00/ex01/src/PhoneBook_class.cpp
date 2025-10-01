/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:48:28 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/01 12:16:56 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "../includes/PhoneBook_class.hpp"

Phonebook::Phonebook( void )
{
	this->id_contacts = 0;
	this->nb_contacts = 0;
	return ;
}

Phonebook::~Phonebook( void )
{
	return ;
}

std::string	Phonebook::is_to_long( std::string input )
{
	if (input.empty())
		return ("");
	if (input.length() > 10)
		return (input.substr(0, 9) + ".");
	return (input);
}

void	Phonebook::add( void )
{
	if (this->id_contacts >= 8)
		this->id_contacts = 0;
	this->contacts[id_contacts].get_infos();
	this->contacts[id_contacts].id = id_contacts;
	this->id_contacts++;
	if (this->nb_contacts < 8)
		this->nb_contacts++;
}

void	Phonebook::search( void )
{
	int	i = 0;

	std::cout << std::endl << std::string(45, '-') << std::endl;
	std::cout << "|" << std::setw(10) << "Index" 
			<< "|" << std::setw(10) << "First Name" 
			<< "|" << std::setw(10) << "Last Name"
			<< "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	std::cout << std::string(45, '-') << std::endl;
	while (i < this->nb_contacts)
	{
		std::string first_name = is_to_long(this->contacts[i].first_name);
		std::string last_name = is_to_long(this->contacts[i].last_name);
		std::string nickname = is_to_long(this->contacts[i].nickname);
		std::cout << "|" << std::setw(10) << i 
				<< "|" << std::setw(10) << first_name
				<< "|" << std::setw(10) << last_name
				<< "|" << std::setw(10) << nickname << "|" << std::endl;
				i++;
	}
	std::cout << std::string(45, '-') << std::endl << std::endl;
}
