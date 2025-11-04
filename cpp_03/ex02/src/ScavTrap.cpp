/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 17:04:25 by jdupuis           #+#    #+#             */
/*   Updated: 2025/11/04 21:15:29 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::~ScavTrap( void )
{}

ScavTrap::ScavTrap( ScavTrap const & other ) : ClapTrap( other.name_ )
{
	*this = other;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap( name ), name_ ( name ), hp_( 100 ), ep_( 50 ), dmg_ ( 20 )
{}

ScavTrap& ScavTrap::operator=( ScavTrap const & a )
{
	this->name_ = a.name_;
	this->hp_ = a.hp_;
	this->ep_ = a.ep_;
	this->dmg_ = a.dmg_;
	return ( *this );
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->ep_)
	{
		std::cout << "ScavTrap " << this->name_ << " attacks " << target << ", causing " << this->dmg_ << " points of damage!" << std::endl;
		this->ep_--;
	}
	else
		std::cout << "ScavTrap " << this->name_ << " could not attack !" << std::endl;
	std::cout << "ScavTrap " << this->name_ << " has " << this->ep_ << " Energy." << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap " << this->name_ << " take damage -" << amount << " HP !" << std::endl;
	if ((this->hp_ - amount) <= 0)
	{
		this->hp_ = 0;
		std::cout << "ScavTrap " << this->name_ << " is dead !" << std::endl;
	}
	else
	{
		this->hp_ -= amount;
		std::cout << "ScavTrap " << this->name_ << " has now " << this->hp_ << " HP." << std::endl;
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	this->hp_ += amount;
	std::cout << "ScavTrap " << this->name_ << " repaire himself by " << amount << " HP !" << std::endl;
	std::cout << "ScavTrap " << this->name_ << " has now " << this->hp_ << " HP." << std::endl;
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScarvTrap " << this->name_ << " is now in Gate keeper mode" << std::endl;
}
