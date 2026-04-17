/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:58:21 by jdupuis           #+#    #+#             */
/*   Updated: 2026/04/17 11:15:56 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"
#include "../includes/Data.hpp"

void printData( const Data* data, const std::string& label )
{
	std::cout << "\n********** " << label << " **********" << std::endl;
	std::cout << "->> x: " << data->x << std::endl;
	std::cout << "->> y: " << data->y << std::endl;
	std::cout << "->> z: " << data->z << std::endl;
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
	std::cout << "\nSerialized uintptr_t: " << raw << std::endl;

	Data* ptr = Serializer::deserialize( raw );
	printData( ptr, "After Deserialization" );

	if (ptr == &data)
		std::cout << "\nPointer check: OK (deserialize returns original address)" << std::endl;
	else
		std::cout << "\nPointer check: KO" << std::endl;

	return ( 0 );
}