/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:59:31 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/16 15:27:57 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name;
		Weapon		&type;
		
	public:
		HumanA( std::string name, Weapon &weapon );
		~HumanA();
		void	attack( void ) const;
};

#endif
