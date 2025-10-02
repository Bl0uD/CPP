/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:14:03 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/02 16:53:19 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>

class Contact {

public:

	Contact( void );
	~Contact( void );
	std::string	get_First_name( void ) const;
	std::string	get_Last_name( void ) const;
	std::string	get_Nickname( void ) const;
	void	set_Id( int v );
	void	set_infos( void );
	
private:
	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;
	int			_id;
};

#endif