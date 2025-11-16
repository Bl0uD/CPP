/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:36:40 by jdupuis           #+#    #+#             */
/*   Updated: 2025/11/16 13:18:57 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::~FragTrap( void )
{
	std::cout << " ~	FragTrap destructor has been called	~" << std::endl;
}

FragTrap::FragTrap( void ) : name_( "Default" ), hp_( 10 ), ep_( 10 ), dmg_ ( 0 )
{
	std::cout << " ~	Default FragTrap constructor has been called	~" << std::endl;
}

FragTrap::FragTrap( FragTrap const & other ) : name_ ( other.name_ ), hp_( other.hp_ ), ep_( other.ep_ ), dmg_ ( other.dmg_ )
{
	std::cout << " ~	FragTrap constructor by copy has been called	~" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap( name ), name_ ( name ), hp_( 100 ), ep_( 100 ), dmg_ ( 30 )
{
	std::cout << " ~	FragTrap constructor by parameter has been called	~" << std::endl;
}

FragTrap& FragTrap::operator=( FragTrap const & a )
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
	if ((this->hp_ - (int)amount) <= 0)
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
