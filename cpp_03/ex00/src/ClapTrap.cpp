/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:04:04 by jdupuis           #+#    #+#             */
/*   Updated: 2025/11/16 13:17:51 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::~ClapTrap( void )
{
	std::cout << " ~	ClapTrap destructor has been called	~" << std::endl;
}

ClapTrap::ClapTrap( void ) : name_( "Default" ), hp_( 10 ), ep_( 10 ), dmg_ ( 0 )
{
	std::cout << " ~	Default ClapTrap constructor has been called	~" << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const & other ) : name_ ( other.name_ ), hp_( other.hp_ ), ep_( other.ep_ ), dmg_ ( other.dmg_ )
{
	std::cout << " ~	ClapTrap constructor by copy has been called	~" << std::endl;
}

ClapTrap::ClapTrap( std::string name ) : name_ ( name ), hp_( 10 ), ep_( 10 ), dmg_ ( 0 )
{
	std::cout << " ~	ClapTrap constructor by parameter has been called	~" << std::endl;
}

ClapTrap& ClapTrap::operator=( ClapTrap const & a )
{
	if (this != &a)
	{
		name_ = a.name_;
		hp_ = a.hp_;
		ep_ = a.ep_;
		dmg_ = a.dmg_;
	}
	return ( *this );
}

void ClapTrap::attack(const std::string& target)
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

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->name_ << " take damage -" << amount << " HP !" << std::endl;
	if ((this->hp_ - (int)amount) <= 0)
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

void ClapTrap::beRepaired(unsigned int amount)
{
	this->hp_ += amount;
	std::cout << "ClapTrap " << this->name_ << " repaire himself by " << amount << " HP !" << std::endl;
	std::cout << "ClapTrap " << this->name_ << " has now " << this->hp_ << " HP." << std::endl;
}
