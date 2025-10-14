/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:01:05 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 14:39:05 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	private:
		ScavTrap();

	protected:
		std::string	name_;
		int			hp_;
		int			ep_;
		int			dmg_;


	public:
		~ScavTrap();
		ScavTrap( std::string name );
		ScavTrap( ScavTrap const & other );
		ScavTrap& operator=( ScavTrap const & a );

		void	guardGate( void );
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};


#endif