/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:35:24 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/30 15:54:54 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"

Form::~Form( void ){}

Form::Form( void ) : _name ("Constructor"), _signed ( false ), _gradeToSign ( 150 ), _gradeToExec ( 150 ) {}

Form::Form( std::string name, int gradeToSign, int gradeToExec ) : _name( name ), _signed ( false ), _gradeToSign ( gradeToSign ), _gradeToExec ( gradeToExec )
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
}

Form::Form( Form const &copy ) : _name ( copy._name ), _signed ( copy._signed ), _gradeToSign ( copy._gradeToSign ), _gradeToExec ( copy._gradeToExec ){}

Form &Form::operator=( Form const &instance )
{
	if (this != &instance)
		this->_signed = instance._signed;
	return ( *this );
}

std::string Form::getName( void ) const
{
	return (this->_name);
}

bool Form::getSigned( void ) const
{
	return ( this->_signed );
}

int Form::getGradeToSign( void ) const
{
	return ( this->_gradeToSign );
}

int Form::getGradeToExec( void ) const
{
	return ( this->_gradeToExec );
}

void Form::beSigned( Bureaucrat const &instance )
{
	if (this->_signed == true)
		throw Form::AlreadySigned();
	if (instance.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::ostream &operator<<( std::ostream &os, const Form &instance )
{
	os << "Form " << instance.getName() << " Grade: " << instance.getGradeToSign() << " & " << instance.getGradeToExec() << " status signed: " << instance.getSigned() << std::endl;
	return ( os );
}
