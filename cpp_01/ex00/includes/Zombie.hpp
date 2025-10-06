/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 12:40:16 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/06 15:32:13 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
public:
	Zombie(std::string name);
	~Zombie();
	void	announce( void );
	void	randomChump( std::string name );
	Zombie*	newZombie( std::string name );

private:
	std::string	_name;
};

#endif