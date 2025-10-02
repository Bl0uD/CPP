/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:47:44 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/02 17:28:23 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include "Utils.hpp"

class Phonebook {

public:

	Phonebook( void );
	~Phonebook( void );
	void		add( void );
	void		search( void );

private:
	Contact _contacts[8];
	int		_id_contacts;
	int		_nb_contacts;
};

#endif