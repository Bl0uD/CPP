/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:48:00 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/01 16:29:56 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook_class.hpp"

std::string	is_to_long( std::string input )
{
	if (input.length() > 10)
		return (input.substr(0, 9) + ".");
	return (input);
}

int	is_whitespace( char c )
{
	if (c == ' ' || c == '\t' || c == '\f'
		|| c == '\n' || c == '\r' || c == '\v')
		return (1);
	return (0);
}

int	only_whitespace( std::string str )
{
	int	i = 0;
	
	while (i < (int)str.length())
	{
		if (!is_whitespace(str[i]))
        	return (0);
		i++;
	}
	return (1);
}

std::string	clear_string( std::string str )
{
	std::string result;
	size_t		i = 0;

	while (i < str.length())
	{
		if (str[i] >= 32 && str[i] <= 126)
			result += str[i];
		else if (str[i] == ' ' || str[i] == '\t')
			result += ' ';
		i++;
	}
	while (!result.empty() && result[0] == ' ')
		result.erase(0, 1);

	while (!result.empty() && result[result.length() - 1] == ' ')
		result.erase(result.length() - 1);

return (result);
}
