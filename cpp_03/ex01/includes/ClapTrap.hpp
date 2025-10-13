/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 14:23:05 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/13 17:47:45 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAPhp_P
# define CLAPTRAPhp_P

# include <iostream>

class ClapTrap
{
	protected:
		ClapTrap();
		
		std::string	name_;
		int			hp_;
		int			ep_;
		int			dmg_;

	public:
		~ClapTrap();
		ClapTrap( std::string name );
		ClapTrap( ClapTrap const & other );
		ClapTrap & operator=( ClapTrap const & a );
		
		std::string	getName() const;
		void	setName( std::string name );
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif