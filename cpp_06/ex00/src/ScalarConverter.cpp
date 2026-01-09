/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:35:27 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/09 02:17:26 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::~ScalarConverter() {};

ScalarConverter::ScalarConverter() {};

ScalarConverter::ScalarConverter( std::string ) {};

ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	*this = copy;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &i)
{
	(void)i;
	return ( *this );
}

static void print_results(std::string const &toChar, bool intImpossible, bool floatImpossible, bool doubleImpossible, int toInt, float toFloat, double toDouble){
	
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
	if (input == "nan" ||
		input == "nanf" ||
		input == "+inf" ||
		input == "-inf" ||
		input == "+inff" ||
		input == "-inff" )
		return ( true );

	if (input.length() == 1 && std::isprint(input[0]))
		return ( true );

	size_t	i = 0;

	if ( input[i] == '+' || input[i] == '-' )
		i++;

	while ( i < input.length() && std::isdigit(input[i]) )
		i++;

	if ( i < input.length() && input[i] == '.')
	{
		i++;
		while ( i < input.length() && std::isdigit(input[i]) )
			i++;
	}

	if ( i == input.length() )
		return ( true );
	
	if ( i == input.length() - 1 && input[i] == 'f' )
		return ( true );

	return ( false );
}

static void convert_single_input(char c, std::string &toChar, int &toInt, float &toFloat, double &toDouble)
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

	if ( input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]) )
		convert_single_input( input[0], toChar, toInt, toFloat, toDouble );
	else
	{
		toDouble = std::strtod( input.c_str(), NULL );

		toFloat = static_cast<float>( toDouble );

		if ( toDouble < INT_MIN || toDouble > INT_MAX || std::isnan(toDouble) )
			intImpossible = true;
		else
			toInt = static_cast<int>( toDouble );

		if ( std::isnan(toDouble) || std::isinf(toDouble) || toInt < 0 || toInt > 127 )
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