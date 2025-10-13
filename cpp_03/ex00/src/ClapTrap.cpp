/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:04:04 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/13 16:56:22 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::~ClapTrap( void )
{}

ClapTrap::ClapTrap( void ) : _hp( 10 ), _ep( 10 ), _dmg ( 0 )
{}

ClapTrap::ClapTrap( std::string name ) : _hp( 10 ), _ep( 10 ), _dmg ( 0 )
{
	this->_name = name;
}

ClapTrap::ClapTrap( ClapTrap const & other ) : _hp( 10 ), _ep( 10 ), _dmg ( 0 )
{
	*this = other;
}

ClapTrap& ClapTrap::operator=( ClapTrap const & a )
{
	this->_name = a._name;
	this->_hp = a._hp;
	this->_ep = a._ep;
	this->_dmg = a._dmg;
	return ( *this );
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_ep)
	{
		std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_dmg << " points of damage!" << std::endl;
		this->_ep--;
	}
	else
		std::cout << "ClapTrap " << this->_name << " could not attack !" << std::endl;
	std::cout << "ClapTrap " << this->_name << " has " << this->_ep << " Energy." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " take damage -" << amount << " HP !" << std::endl;
	if ((this->_hp - amount) <= 0)
	{
		this->_hp = 0;
		std::cout << "ClapTrap " << this->_name << " is dead !" << std::endl;
	}
	else
	{
		this->_hp -= amount;
		std::cout << "ClapTrap " << this->_name << " has now " << this->_hp << " HP." << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	this->_hp += amount;
	std::cout << "ClapTrap " << this->_name << " repaire himself by " << amount << " HP !" << std::endl;
	std::cout << "ClapTrap " << this->_name << " has now " << this->_hp << " HP." << std::endl;
}
