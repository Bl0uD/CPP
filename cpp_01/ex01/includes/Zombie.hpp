/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:57:11 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/16 15:20:14 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	private:
		std::string	name;

	public:
		Zombie();
		~Zombie();
		void	announce();
		void	setName( std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif