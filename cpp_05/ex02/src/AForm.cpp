/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:35:24 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/05 11:38:00 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::~AForm( void ){}

AForm::AForm( void ) : _name ("Constructor"), _signed ( false ), _gradeToSign ( 150 ), _gradeToExec ( 150 ) {}

AForm::AForm( std::string name, int gradeToSign, int gradeToExec ) : _name( name ), _signed ( false ), _gradeToSign ( gradeToSign ), _gradeToExec ( gradeToExec )
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

std::string AForm::getName( void ) const
{
	return (this->_name);
}

bool AForm::getSigned( void ) const
{
	return ( this->_signed );
}

int AForm::getGradeToSign( void ) const
{
	return ( this->_gradeToSign );
}

int AForm::getGradeToExec( void ) const
{
	return ( this->_gradeToExec );
}

void AForm::beSigned( Bureaucrat const &instance )
{
	if (this->_signed == true)
		throw AForm::AlreadySigned();
	if (instance.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

std::ostream &operator<<( std::ostream &os, const AForm &instance )
{
	os << "AForm " << instance.getName() << " Grade: " << instance.getGradeToSign() << " & " << instance.getGradeToExec() << " status signed: " << instance.getSigned() << std::endl;
	return ( os );
}
