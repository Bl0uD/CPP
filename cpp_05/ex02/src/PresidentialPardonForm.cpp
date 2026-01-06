/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:03:21 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/06 14:46:29 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::~PresidentialPardonForm( void ){}

PresidentialPardonForm::PresidentialPardonForm( void ){}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &instance ) : AForm(instance), _target(instance._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const &instance )
{
	if (this != &instance)
		this->_target = instance._target;
	return ( *this );
}

std::string PresidentialPardonForm::getTarget( void ) const
{
	return (this->_target);
}

void PresidentialPardonForm::execute( Bureaucrat const &instance ) const
{
	if ( instance.getGrade() > this->getGradeToExec() )
		throw AForm::GradeTooLowToExecException();
	if ( instance.getGrade() > this->getGradeToSign() )
		throw AForm::GradeTooLowToSignException();
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::ostream &operator<<( std::ostream &os, const PresidentialPardonForm &instance )
{
	os << "PresidentialPardonForm " << instance.getName() << " Grade: " << instance.getGradeToSign() << " & " << instance.getGradeToExec() << " status signed: " << instance.getSigned() << std::endl;
	return ( os );
}
