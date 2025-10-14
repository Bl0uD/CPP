/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:48:28 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/13 17:48:26 by jdupuis          ###   ########.fr       */
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
	this->_contacts[_id_contacts].set_infos();
	this->_contacts[_id_contacts].set_Id( _id_contacts );
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
		std::string _firstname_ = is_to_long(this->_contacts[i].get_Firstname_());
		std::string _lastname_ = is_to_long(this->_contacts[i].get_Lastname_());
		std::string _nickname = is_to_long(this->_contacts[i].get_Nickname());
		std::cout << "|" << std::setw(10) << i 
				<< "|" << std::setw(10) << _firstname_
				<< "|" << std::setw(10) << _lastname_
				<< "|" << std::setw(10) << _nickname << "|" << std::endl;
				i++;
	}
	std::cout << std::string(45, '-') << std::endl << std::endl;
}
