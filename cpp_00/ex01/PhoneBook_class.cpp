/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:48:28 by jdupuis           #+#    #+#             */
/*   Updated: 2025/09/29 18:01:29 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook_class.hpp"

Phonebook::Phonebook( void )
{
	std::cout << "Constructor called" << std::endl;
	return;	
}

Phonebook::~Phonebook( void )
{
	std::cout << "Destructor called" << std::endl;
	return;	
}
