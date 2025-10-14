/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:10:10 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 17:49:58 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type_ = "Cat";
	this->_brain = new Brain();
}

Cat::Cat( std::string name )
{
	std::cout << "Cat constructor by parameter called" << std::endl;
	this->type_ = "Cat";
	this->name_ = name;
}

Cat::Cat( Cat const & other ) : AAnimal ( other )
{
	std::cout << "Cat constructor by copy called" << std::endl;
	*this = other;
}

Cat const& Cat::operator=( Cat const & a )
{
	this->name_ = a.name_;
	return ( *this );
}

std::string	Cat::getName( void ) const
{
	return ( this->name_ );
}

void	Cat::makeSound( void ) const
{
	std::cout << "Miaouuuuu ! " << std::endl;
}
