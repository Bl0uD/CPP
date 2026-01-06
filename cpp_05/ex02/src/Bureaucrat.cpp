/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:14:44 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/05 19:09:09 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

Bureaucrat::~Bureaucrat(){}

Bureaucrat::Bureaucrat(){}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name( name )
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade = grade;
	std::cout << "new Bureaucrat created, named: " << this->_name << ", grade: " << this->_grade << "." << std::endl;
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
	if (this->_grade > 1)
		this->_grade--;
	else
		throw Bureaucrat::GradeTooLowException();
	std::cout << this->_name << ": current grade is : " << this->_grade << std::endl;
}

void	Bureaucrat::decrementGrade( void )
{
	if (this->_grade < 150)
		this->_grade++;
	else
		throw Bureaucrat::GradeTooHighException();
	std::cout << this->_name << ": current grade is : " << this->_grade << std::endl;
}

void Bureaucrat::signForm( AForm &form )
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() 
				  << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm( AForm const &form ) const
{
	try
	{
		form.execute( *this );
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() 
				  << " because " << e.what() << std::endl;
	}
}

std::ostream &operator<<( std::ostream &os, Bureaucrat const &instance )
{
	os << instance.getName() << ", bureaucrat grade " << instance.getGrade() << "." << std::endl;
	return ( os );
}
