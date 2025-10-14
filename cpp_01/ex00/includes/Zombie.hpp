/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:40:16 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/13 17:48:26 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEhp_P
# define ZOMBIEhp_P

#include <iostream>

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie();
		void	announce( void );
		
	private:
		std::string	name_;
};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

#endif