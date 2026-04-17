/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:35:27 by jdupuis           #+#    #+#             */
/*   Updated: 2026/04/17 11:15:56 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {};

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter( std::string ) {};

ScalarConverter::ScalarConverter( ScalarConverter const &copy )
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=( ScalarConverter const &instance )
{
	(void)instance;
	return ( *this );
}

static bool is_pseudo_literal( std::string const &input )
{
	return (input == "nan" ||
		input == "nanf" ||
		input == "+inf" ||
		input == "-inf" ||
		input == "+inff" ||
		input == "-inff");
}

static void print_results( std::string const &toChar, bool intImpossible, bool floatImpossible, bool doubleImpossible, int toInt, float toFloat, double toDouble )
{
	std::cout << "char: " << toChar << std::endl;

	if (intImpossible)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << toInt << std::endl;

	if (floatImpossible)
		std::cout << "float: impossible" << std::endl;
	else
		std::cout << "float: " << std::fixed << std::setprecision(1) << toFloat << "f" << std::endl;

	if (doubleImpossible)
		std::cout << "double: impossible" << std::endl;
	else
		std::cout << "double: " << std::fixed << std::setprecision(1) << toDouble << std::endl;
}

static bool parser( std::string const &input )
{
	if ( is_pseudo_literal(input) )
		return ( true );

	if ( input.length() == 3 && input[0] == '\'' && input[2] == '\'' && std::isprint(input[1]) )
		return ( true );

	if ( input.length() == 1 && std::isprint(input[0]) )
		return ( true );

	size_t	i = 0;
	bool	hasDigit = false;

	if ( input[i] == '+' || input[i] == '-' )
		i++;

	while ( i < input.length() && std::isdigit(input[i]) )
	{
		hasDigit = true;
		i++;
	}

	if ( i < input.length() && input[i] == '.')
	{
		i++;
		while ( i < input.length() && std::isdigit(input[i]) )
		{
			hasDigit = true;
			i++;
		}
	}

	if ( !hasDigit )
		return ( false );

	if ( i == input.length() )
		return ( true );
	
	if ( i == input.length() - 1 && input[i] == 'f' )
		return ( true );

	return ( false );
}

static void convert_single_input( char c, std::string &toChar, int &toInt, float &toFloat, double &toDouble )
{
	toChar = "'";
	toChar += c;
	toChar += "'";
	toInt = static_cast<int>(c);
	toFloat = static_cast<float>(c);
	toDouble = static_cast<double>(c);
}

void	ScalarConverter::convert( std::string const &input )
{
	if ( !parser(input) )
	{
		std::cout << "Error : Invalid input" << std::endl;
		return ;
	}

	std::string toChar = "impossible";
	int		toInt = 0;
	float	toFloat = 0.0f;
	double	toDouble = 0.0;
	bool	intImpossible = false;
	bool	floatImpossible = false;
	bool	doubleImpossible = false;

	if ( (input.length() == 3 && input[0] == '\'' && input[2] == '\'' && std::isprint(input[1])) )
		convert_single_input( input[1], toChar, toInt, toFloat, toDouble );
	else if ( input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]) )
		convert_single_input( input[0], toChar, toInt, toFloat, toDouble );
	else
	{
		errno = 0;
		char *end = NULL;
		toDouble = std::strtod( input.c_str(), &end );

		if ( errno == ERANGE && std::isinf(toDouble) && !is_pseudo_literal(input) )
			doubleImpossible = true;

		if ( doubleImpossible )
			floatImpossible = true;
		else if ( std::isnan(toDouble) || std::isinf(toDouble) )
			toFloat = static_cast<float>( toDouble );
		else if ( toDouble <= std::numeric_limits<float>::max() && toDouble >= -std::numeric_limits<float>::max() )
			toFloat = static_cast<float>( toDouble );
		else
			floatImpossible = true;

		if ( end && *end != '\0' && !(*end == 'f' && *(end + 1) == '\0') )
		{
			std::cout << "Error : Invalid input" << std::endl;
			return ;
		}

		if ( doubleImpossible || toDouble < INT_MIN || toDouble > INT_MAX || std::isnan(toDouble) || std::isinf(toDouble) )
			intImpossible = true;
		else
			toInt = static_cast<int>( toDouble );

		if ( intImpossible || toInt < 0 || toInt > 127 )
			toChar = "impossible";
		else if ( toInt < 32 || toInt > 126 )
			toChar = "Non displayable";
		else
		{
			toChar = "'";
			toChar += static_cast<char>( toInt );
			toChar += "'";
		}
	}
	
	print_results( toChar, intImpossible, floatImpossible, doubleImpossible, toInt, toFloat, toDouble );
}