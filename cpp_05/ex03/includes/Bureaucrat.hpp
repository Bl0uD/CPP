/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 12:13:05 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/06 14:53:10 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <fstream>
# include <string>

class AForm;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
	
	public:
		~Bureaucrat();
		Bureaucrat();
		Bureaucrat( std::string name, int grade );
		Bureaucrat( Bureaucrat const &copy );
		Bureaucrat &operator=( Bureaucrat const &instance );
		
		std::string getName( void ) const;
		int	getGrade( void ) const;

		void incrementGrade();
		void decrementGrade();
		
		void signForm( AForm &instance );
		void executeForm( AForm const &form ) const;
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too high !!");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too low !!");
				}
		};
};

std::ostream &operator<<( std::ostream &os, Bureaucrat const &instance );

#endif