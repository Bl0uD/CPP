/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:02:00 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/06 18:00:07 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm( void ){}

ShrubberyCreationForm::ShrubberyCreationForm( void ){}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &instance ) : AForm(instance), _target(instance._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=( ShrubberyCreationForm const &instance )
{
	if (this != &instance)
		this->_target = instance._target;
	return ( *this );
}

std::string ShrubberyCreationForm::getTarget( void ) const
{
	return (this->_target);
}

void ShrubberyCreationForm::execute( Bureaucrat const &instance ) const
{
	if ( !this->getSigned() )
		throw AForm::NotSigned();
	if ( instance.getGrade() > this->getGradeToExec() )
		throw AForm::GradeTooLowToExecException();
	std::ofstream outfile ( this->getTarget() + "_shrubbery" );
	outfile << "         &&& &&  & &&" << std::endl;
	outfile << "      && &\\/&\\|& ()|/ @, &&" << std::endl;
	outfile << "      &\\/(/&/&||/& /_/)_&/_&" << std::endl;
	outfile << "   &() &\\/&|()|/&\\/ '%\\\" & ()" << std::endl;
	outfile << "  &_\\_&&_\\ |& |&&/&__%_/_& &&" << std::endl;
	outfile << "&&   && & &| &| /& & % ()& /&&" << std::endl;
	outfile << " ()&_---()&\\&\\|&&-&&--%---()~" << std::endl;
	outfile << "     &&     \\|||" << std::endl;
	outfile << "             |||" << std::endl;
	outfile << "             |||" << std::endl;
	outfile << "       , -=-~  .-^- _" << std::endl;
	outfile.close();
}

std::ostream &operator<<( std::ostream &os, const ShrubberyCreationForm &instance )
{
	os << "ShrubberyCreationForm " << instance.getName() << " Grade: " << instance.getGradeToSign() << " & " << instance.getGradeToExec() << " status signed: " << instance.getSigned() << std::endl;
	return ( os );
}
