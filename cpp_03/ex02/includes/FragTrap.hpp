/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:36:31 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 14:47:14 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class	FragTrap : public ClapTrap
{
	private:
		FragTrap();

	protected:
		std::string	name_;
		int			hp_;
		int			ep_;
		int			dmg_;


	public:
		~FragTrap();
		FragTrap( std::string name );
		FragTrap( FragTrap const & other );
		FragTrap& operator=( FragTrap const & a );

		void	highFivesGuys( void );
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};


#endif