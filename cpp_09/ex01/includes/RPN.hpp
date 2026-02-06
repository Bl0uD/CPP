/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 14:57:01 by jdupuis           #+#    #+#             */
/*   Updated: 2026/02/06 16:51:21 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <string>
# include <sstream>
# include <exception>

class RPN
{
	private:
		std::stack<double> _stack;
		double	_plus( double a, double b );
		double	_minus( double a, double b );
		double	_multiply( double a, double b );
		double	_divide( double a, double b );
		void	_executeStack( double (RPN::*f)(double, double) );

	public:
		~RPN();
		RPN();
		RPN( const std::string &av );
		RPN( const RPN &copy );
		RPN &operator=( const RPN &instance );

		double	getResult();
		void	execute( const std::string &inputStr );

	class emptyStackException : public std::runtime_error
	{
		public:
			explicit emptyStackException(const std::string& msg);
	};

	class invalidArgException : public std::runtime_error
	{
		public:
			explicit invalidArgException(const std::string& msg);
	};

	class divisionByZero : public std::runtime_error
	{
		public:
			explicit divisionByZero(const std::string& msg);
	};
};

#endif