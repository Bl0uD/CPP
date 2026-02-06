/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 00:50:32 by jdupuis           #+#    #+#             */
/*   Updated: 2026/02/06 16:00:42 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <exception>
# include <fstream>
# include <iostream>
# include <map>
# include <string>
# include <sstream>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_exchangeMap;
		void	_readDatabase();
		bool	_valideDate( std::string const &date );
		double	_valideBtcAmount( std::string const &price );
		void	_displayExchangeResult( std::string const &date, double price );
		
	public:
		~BitcoinExchange();
		BitcoinExchange();
		BitcoinExchange( std::string );
		BitcoinExchange( const BitcoinExchange &copy );
		BitcoinExchange &operator=( const BitcoinExchange &instance );

		void	execute( char const *fileName );

		class CannotOpenFileException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ( "Error: could not open file." );
				}
		};
		
		class InvalidInputLineFormatException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ( "Error: Invalid line format. Expected 'date,exchange_rate'" );
				}
		};

		class InvalidDataLineFormatException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ( "Error: Invalid line format. Expected 'date | value'" );
				}
		};
		
		class InvalidDateFormatException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ( "Error: Invalid date format. Expected 'YYYY-MM-DD'" );
				}
		};

		class InvalidPriceFormatException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ( "Error: Invalid price format. Expected a number between 0.0 and 1000.0" );
				}
		};
};

#endif