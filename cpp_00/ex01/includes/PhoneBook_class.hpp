/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook_class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 17:47:44 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/13 17:47:45 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASShp_P
# define PHONEBOOK_CLASShp_P

#include "Contact_class.hpp"
#include "utils.hpp"

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