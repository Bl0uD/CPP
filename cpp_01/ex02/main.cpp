/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 16:35:56 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/06 16:56:12 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( void )
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout << &str << " : The memory adresss of the string variable" << std::endl;
	std::cout << stringPTR << " : The memory adresss held by stringPTR" << std::endl;
	std::cout << &stringREF << " : The memory adresss held by stringREF" << std::endl << std::endl;

	std::cout << str << " : The value of the string variable" << std::endl;
	std::cout << *stringPTR << " : The value pointed to by stringPTR" << std::endl;
	std::cout << stringREF << " : The value pointed to by stringREF" << std::endl;
	
	return (0);
}
