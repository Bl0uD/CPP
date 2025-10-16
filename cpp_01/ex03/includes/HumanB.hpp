/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:59:43 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/16 15:27:44 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
	private:
		std::string	const	name;
		Weapon				*type;
		
	public:
		HumanB( std::string name );
		~HumanB();
		void		attack( void ) const;
		void		setWeapon( Weapon &weapon );
};

#endif
