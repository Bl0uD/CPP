/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:35:15 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/30 15:54:54 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool 				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;
		
	public:
		~Form( void );
		Form( void );
		Form( std::string name, int gradeToSign, int gradeToExec );
		Form( Form const &copy );
		Form &operator=( Form const &instance );

		std::string getName( void ) const;
		bool getSigned( void ) const;
		int getGradeToSign( void ) const;
		int getGradeToExec( void ) const;

		void beSigned( Bureaucrat const &instance );
		
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

		class AlreadySigned : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Already signed.");
				}
		};
};

std::ostream &operator<<( std::ostream &os, Form const &instance );

#endif