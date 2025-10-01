/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:48:28 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/01 23:15:49 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include "../includes/PhoneBook_class.hpp"

Phonebook::Phonebook( void )
{
	this->_id_contacts = 0;
	this->_nb_contacts = 0;
	return ;
}

Phonebook::~Phonebook( void )
{
	return ;
}

void	Phonebook::add( void )
{
	if (this->_id_contacts >= 8)
		this->_id_contacts = 0;
	this->_contacts[_id_contacts].get_infos();
	this->_contacts[_id_contacts].id = _id_contacts;
	this->_id_contacts++;
	if (this->_nb_contacts < 8)
		this->_nb_contacts++;
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
	while (i < this->_nb_contacts)
	{
		std::string first_name = is_to_long(this->_contacts[i].first_name);
		std::string last_name = is_to_long(this->_contacts[i].last_name);
		std::string nickname = is_to_long(this->_contacts[i].nickname);
		std::cout << "|" << std::setw(10) << i 
				<< "|" << std::setw(10) << first_name
				<< "|" << std::setw(10) << last_name
				<< "|" << std::setw(10) << nickname << "|" << std::endl;
				i++;
	}
	std::cout << std::string(45, '-') << std::endl << std::endl;
}
