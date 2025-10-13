/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:23:05 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/13 16:41:37 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	private:
		ClapTrap();
		
		std::string	_name;
		int			_hp;
		int			_ep;
		int			_dmg;

	public:
		~ClapTrap();
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const & other );
		ClapTrap & operator=( ClapTrap const & a );
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif