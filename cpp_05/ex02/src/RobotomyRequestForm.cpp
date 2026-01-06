/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:02:44 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/06 15:16:05 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::~RobotomyRequestForm( void ){}

RobotomyRequestForm::RobotomyRequestForm( void ){}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &instance ) : AForm(instance), _target(instance._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const &instance )
{
	if (this != &instance)
		this->_target = instance._target;
	return ( *this );
}

std::string RobotomyRequestForm::getTarget( void ) const
{
	return (this->_target);
}

void RobotomyRequestForm::execute( Bureaucrat const &instance ) const
{
	if ( instance.getGrade() > this->getGradeToExec() )
		throw AForm::GradeTooLowToExecException();
	if ( instance.getGrade() > this->getGradeToSign() )
		throw AForm::GradeTooLowToSignException();
	std::srand(std::time(0));
	if ( std::rand() % 2 )
		std::cout << "Makes some drilling noises ! " << this->getTarget() << " has been robotomized !" << std::endl;
	else
		std::cout << "The robotomy failed for " << this->getTarget() << std::endl;
}

std::ostream &operator<<( std::ostream &os, const RobotomyRequestForm &instance )
{
	os << "RobotomyRequestForm " << instance.getName() << " Grade: " << instance.getGradeToSign() << " & " << instance.getGradeToExec() << " status signed: " << instance.getSigned() << std::endl;
	return ( os );
}
