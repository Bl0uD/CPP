/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:14:44 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/29 13:50:35 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name( name )
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
	std::cout << "new Bureaucrat created, named: " << name << ", grade: " << _grade << "." << std::endl;
}

Bureaucrat::Bureaucrat( Bureaucrat const &copy ) : _name( copy._name ), _grade( copy._grade ){}

Bureaucrat	&Bureaucrat::operator=( Bureaucrat const &instance )
{
	if (this != &instance)
		this->_grade = instance._grade;
	return ( *this );
}

std::string	Bureaucrat::getName( void ) const
{
	return ( this->_name );
}

int	Bureaucrat::getGrade( void ) const
{
	return ( this->_grade );
}

void	Bureaucrat::incrementGrade( void )
{
	if (_grade > 1)
		_grade--;
	else
		throw Bureaucrat::GradeTooLowException();
	std::cout << this->_name << ": current grade is : " << this->_grade << std::endl;
}

void	Bureaucrat::decrementGrade( void )
{
	if (_grade < 150)
		_grade++;
	else
		throw Bureaucrat::GradeTooHighException();
	std::cout << this->_name << ": current grade is : " << this->_grade << std::endl;
}

std::ostream &operator<<( std::ostream &os, Bureaucrat const &instance )
{
	os << instance.getName() << ", bureaucrat grade " << instance.getGrade() << "." << std::endl;
	return ( os );
}
