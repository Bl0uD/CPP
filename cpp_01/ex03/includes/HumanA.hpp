/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:59:31 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/13 17:48:26 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANAhp_P
# define HUMANAhp_P

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private:
		std::string	name_;
		Weapon		&_weaponType;
		
	public:
		HumanA( std::string name, Weapon &weapon );
		~HumanA();
		void	attack( void ) const;
};

#endif
