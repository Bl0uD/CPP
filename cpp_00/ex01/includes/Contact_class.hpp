/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact_class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:14:03 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/01 15:43:06 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>

class Contact {

public:

	Contact( void );
	~Contact( void );
	void		get_infos( void );
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	int			id;
	
private:
	std::string	phone_number;
	std::string	darkest_secret;
};

#endif