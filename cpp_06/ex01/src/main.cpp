/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:58:21 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/09 16:40:18 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

void printData( const Data* data, const std::string& label )
{
	std::cout << "\n********** " << label << " **********" << std::endl;
	std::cout << "->> x: " << data->x << std::endl;
	std::cout << "->> y: " << data->y << std::endl;
	std::cout << "->> z: " << data->y << std::endl;
	std::cout << "->> id : " << data->id << std::endl;
	std::cout << "->> seed : " << data->seed << std::endl;
	std::cout << "->> password : " << data->password << std::endl;
}

int main( void )
{
	Data data = {
		888,					// x
		777,					// y
		555,					// z
		"alert__reaction",		// id
		"couple__grown",		// seed
		"jumpy___cream"			// pasword
	};

	printData( &data, "Before Serialization" );

	uintptr_t raw = Serializer::serialize( &data );
	std::cout << "\033[1;33m\nSerialized uintptr_t: " << "\033[0m" << raw << "  😎"  << std::endl;

	Data* ptr = Serializer::deserialize( raw );
	printData( ptr, "After Deserialization" );

	return ( 0 );
}