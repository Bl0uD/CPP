/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:14:03 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/13 17:48:26 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASShp_P
# define CONTACT_CLASShp_P

#include <iostream>

class Contact {

public:

	Contact( void );
	~Contact( void );
	std::string	get_Firstname_( void ) const;
	std::string	get_Lastname_( void ) const;
	std::string	get_Nickname( void ) const;
	void	set_Id( int v );
	void	set_infos( void );
	
private:
	std::string	_firstname_;
	std::string	_lastname_;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;
	int			_id;
};

#endif