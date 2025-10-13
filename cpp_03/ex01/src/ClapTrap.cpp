/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:04:04 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/13 18:05:32 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::~ClapTrap( void )
{}

ClapTrap::ClapTrap( void ) : hp_( 10 ), ep_( 10 ), dmg_ ( 0 )
{}

ClapTrap::ClapTrap( std::string name ) : name_ ( name ), hp_( 10 ), ep_( 10 ), dmg_ ( 0 )
{}

ClapTrap::ClapTrap( ClapTrap const & other ) : hp_( 10 ), ep_( 10 ), dmg_ ( 0 )
{
	*this = other;
}

ClapTrap& ClapTrap::operator=( ClapTrap const & a )
{
	this->name_ = a.name_;
	this->hp_ = a.hp_;
	this->ep_ = a.ep_;
	this->dmg_ = a.dmg_;
	return ( *this );
}

std::string	ClapTrap::getName( void ) const
{
	return (this->name_);
}

void	ClapTrap::setName( std::string name )
{
	this->name_ = name;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->ep_)
	{
		std::cout << "ClapTrap " << this->name_ << " attacks " << target << ", causing " << this->dmg_ << " points of damage!" << std::endl;
		this->ep_--;
	}
	else
		std::cout << "ClapTrap " << this->name_ << " could not attack !" << std::endl;
	std::cout << "ClapTrap " << this->name_ << " has " << this->ep_ << " Energy." << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name_ << " take damage -" << amount << " HP !" << std::endl;
	if ((this->hp_ - amount) <= 0)
	{
		this->hp_ = 0;
		std::cout << "ClapTrap " << this->name_ << " is dead !" << std::endl;
	}
	else
	{
		this->hp_ -= amount;
		std::cout << "ClapTrap " << this->name_ << " has now " << this->hp_ << " HP." << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	this->hp_ += amount;
	std::cout << "ClapTrap " << this->name_ << " repaire himself by " << amount << " HP !" << std::endl;
	std::cout << "ClapTrap " << this->name_ << " has now " << this->hp_ << " HP." << std::endl;
}
