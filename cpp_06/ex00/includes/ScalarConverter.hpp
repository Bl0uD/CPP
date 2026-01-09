/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:35:16 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/09 02:15:44 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <limits>
# include <cstdlib>
# include <cmath>	// for isnan, isinf
# include <cerrno>	// for errno, ERANGE
# include <climits>	// for INT_MAX, INT_MIN
# include <cctype>	// for isprint, isdigit

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter( std::string );
		ScalarConverter( ScalarConverter const &copy );
		ScalarConverter &operator=( ScalarConverter const &instance );

	public:
		virtual ~ScalarConverter(); // Destructor can remain public or protected, but allowing inheritance is rare for static classes. Usually private too for strict utility class, but standard compliant as long as constructor is private.
		static void convert( std::string const &input );
};

#endif
