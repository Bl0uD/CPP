/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:57:11 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/13 17:48:26 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIEhp_P
# define ZOMBIEhp_P

#include <iostream>

class Zombie
{
private:
	std::string	name_;

public:
	Zombie();
	~Zombie();
	void	announce();
	void	setName( std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif