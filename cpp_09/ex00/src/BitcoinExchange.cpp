/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 00:50:43 by jdupuis           #+#    #+#             */
/*   Updated: 2026/02/06 16:00:59 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/BitcoinExchange.hpp"

BitcoinExchange::~BitcoinExchange( void )
{
	// std::cout << "BitcoinExchange destructor called." << std::endl;
}

BitcoinExchange::BitcoinExchange( void )
{
	_readDatabase();
	// std::cout << "BitcoinExchange default constructor called." << std::endl;
}

BitcoinExchange::BitcoinExchange( std::string )
{
	// std::cout << "BitcoinExchange parametric constructor called." << std::endl;
}

BitcoinExchange::BitcoinExchange( BitcoinExchange const &copy )
{
	// std::cout << "BitcoinExchange copy constructor called." << std::endl;
	*this = copy;
}

BitcoinExchange	&BitcoinExchange::operator=( BitcoinExchange const &instance )
{
	if (this != &instance)
		_exchangeMap = instance._exchangeMap;
	return ( *this );
}

void	clearStr( std::string &str )
{
	size_t	i = 0;

	while ( i < str.length() )
	{
		if ( isspace(str[i]) )
			str.erase(i, 1);
		else
			i++;
	}
}

bool	BitcoinExchange::_valideDate( std::string const &date )
{
	bool	valideDate = true;
	bool	impossibleDate = false;
	char	sep1;
	char	sep2;
	int 	year;
	int 	month;
	int		day;

    if ( date.length() != 10 )
		valideDate = false;
	else if ( date[4] != '-' || date[7] != '-' )
		valideDate = false;

    std::istringstream ss( date );
    ss >> year >> sep1 >> month >> sep2 >> day;

    if ( valideDate == true && (ss.fail() || sep1 != '-' || sep2 != '-') )
		valideDate = false;
    else if ( month < 1 || month > 12 )
		valideDate = false;
    else if ( day < 1 || day > 31 )
		valideDate = false;
	if ( valideDate == true )
	{
		int maxDays = 31;
		if ( month == 4 || month == 6 || month == 9 || month == 11 )
			maxDays = 30;
		else if ( month == 2 )
		{
			bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
			if ( isLeapYear )
				maxDays = 29;
			else
				maxDays = 28;
		}
		
		if ( day > maxDays )
		{
			valideDate = false;
			impossibleDate = true;
		}
	}
	if ( valideDate == false )
	{
		if ( impossibleDate )
			std::cout << "Error: impossible date => " << date << std::endl;
		else
			std::cout << "Error: bad input => " << date << std::endl;
	}
	return ( valideDate );
}

double	BitcoinExchange::_valideBtcAmount( std::string const &price )
{
	double	amountBtc;
	std::istringstream priceStream( price );

	if ( !(priceStream >> amountBtc) )
	{
		std::cout << "Error: bad input => " << price << std::endl;
		return ( -1 );
	}
	if (amountBtc < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return ( -1 );
	}
	else if (amountBtc > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return ( -1 );
	}
	return (amountBtc);
}

void	BitcoinExchange::_displayExchangeResult( std::string const &date, double btcAmount )
{
	std::map<std::string, double>::iterator	it = _exchangeMap.find( date );

	if ( it != _exchangeMap.end() )
		std::cout << date << " => " << btcAmount << " = " << btcAmount * it->second << std::endl;
	else
	{
		std::map<std::string, double>::iterator it2 = _exchangeMap.lower_bound( date );
		if ( it2 == _exchangeMap.begin() )
			std::cout << date << " => " << btcAmount << " = " << btcAmount * it2->second << std::endl;
		else
		{
			it2--;
			std::cout << date << " => " << btcAmount << " = " << btcAmount * it2->second << std::endl;
		}
	}
}

void	BitcoinExchange::_readDatabase()
{
       std::ifstream file("data.csv");
        if (!file.is_open())
            throw CannotOpenFileException();

        std::string line;

        std::getline(file, line);
        if (line != "date,exchange_rate")
            throw InvalidInputLineFormatException();
        while (std::getline(file, line))
		{
            std::string date, price;
            std::istringstream ss(line);
            std::getline(ss, date, ',');
            std::getline(ss, price, ',');

            double priceBtc;
            std::istringstream priceStream(price);
            if (!(priceStream >> priceBtc))
				throw InvalidPriceFormatException();
            _exchangeMap[date] = priceBtc;
        }
        file.close();
}

void	BitcoinExchange::execute( char const *fileName )
{
	std::ifstream	file( fileName );
	if ( !file.is_open() )
		throw CannotOpenFileException();

	std::string	line;

	std::getline( file, line );
	if ( line != "date | value" )
		throw InvalidDataLineFormatException();
	while ( std::getline(file, line) )
	{
		std::istringstream ss( line );
		std::string	date;
		std::string valueStr;
		
		std::getline( ss, date, '|' );
		std::getline( ss, valueStr, '|' );

		clearStr( date );
		clearStr( valueStr );
		
		if ( date.empty() || valueStr.empty() )
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		if ( !_valideDate( date ) )
			continue;
		double	amountBtc = _valideBtcAmount( valueStr );
		if ( amountBtc != -1 )
			_displayExchangeResult( date, amountBtc );
	}
	file.close();
}
