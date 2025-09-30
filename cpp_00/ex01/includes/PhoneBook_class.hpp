/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:47:44 by jdupuis           #+#    #+#             */
/*   Updated: 2025/09/30 18:04:48 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact_class.hpp"

class Phonebook {

public:

	Phonebook( void );
	~Phonebook( void );
	void		add( void );
	void		search( void );
	std::string	is_to_long( std::string );

private:
	Contact contacts[8];
	int		id_contacts;
	int		nb_contacts;
};

#endif