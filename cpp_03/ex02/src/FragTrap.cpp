/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:36:40 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 14:43:32 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::~FragTrap( void )
{}

FragTrap::FragTrap( FragTrap const & other ) : ClapTrap( other.name_ )
{
	*this = other;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name ), name_ ( name ), hp_( 100 ), ep_( 100 ), dmg_ ( 30 )
{}

FragTrap& FragTrap::operator=( FragTrap const & a )
{
	this->name_ = a.name_;
	this->hp_ = a.hp_;
	this->ep_ = a.ep_;
	this->dmg_ = a.dmg_;
	return ( *this );
}

void	FragTrap::attack(const std::string& target)
{
	if (this->ep_)
	{
		std::cout << "FragTrap " << this->name_ << " attacks " << target << ", causing " << this->dmg_ << " points of damage!" << std::endl;
		this->ep_--;
	}
	else
		std::cout << "FragTrap " << this->name_ << " could not attack !" << std::endl;
	std::cout << "FragTrap " << this->name_ << " has " << this->ep_ << " Energy." << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap " << this->name_ << " take damage -" << amount << " HP !" << std::endl;
	if ((this->hp_ - amount) <= 0)
	{
		this->hp_ = 0;
		std::cout << "FragTrap " << this->name_ << " is dead !" << std::endl;
	}
	else
	{
		this->hp_ -= amount;
		std::cout << "FragTrap " << this->name_ << " has now " << this->hp_ << " HP." << std::endl;
	}
}

void	FragTrap::beRepaired(unsigned int amount)
{
	this->hp_ += amount;
	std::cout << "FragTrap " << this->name_ << " repaire himself by " << amount << " HP !" << std::endl;
	std::cout << "FragTrap " << this->name_ << " has now " << this->hp_ << " HP." << std::endl;
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << this->name_ << " high-fives his guys." << std::endl;
}
