/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Aform.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:01:16 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/05 19:03:56 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool 				_signed;
		const int			_gradeToSign;
		const int			_gradeToExec;
		
	public:
		~AForm( void );
		AForm( void );
		AForm( std::string name, int gradeToSign, int gradeToExec );
		AForm( AForm const &copy );
		AForm &operator=( AForm const &instance );

		std::string getName( void ) const;
		bool getSigned( void ) const;
		int getGradeToSign( void ) const;
		int getGradeToExec( void ) const;

		void beSigned( Bureaucrat const &instance );
		virtual void execute( Bureaucrat const &instance ) const = 0;
		
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too high.");
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too low.");
				}
		};
		
		class GradeTooLowToExecException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too low to execute this form.");
				}
		};
		
		class GradeTooLowToSignException : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Grade is too low to sign this form.");
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

		class NotSigned : public std::exception
		{
			public:
				virtual const char* what() const throw()
				{
					return ("Not signed.");
				}
		};
};

#endif