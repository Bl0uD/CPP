/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:58:36 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/09 17:35:38 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"

void tester()
{
    Base *surprise_base = generate();
    
    if ( !surprise_base )
	{
        std::cout << "Error: generate() returned NULL" << std::endl;
        return ;
    }
    
    std::cout << "Pointer identification: ";
    identify( surprise_base );
    
    std::cout << "Reference identification: ";
    identify( *surprise_base );
    
    delete surprise_base;

}

int main( void )
{
    std::cout << "<<=== Dynamic Cast Tester ===>>\n" << std::endl;
    
    int amount_test = 3;       // input number of test you want.

    for ( int i = 1; i <= amount_test; ++i )
	{ 
        std::cout << "-->> Run " << i << ":" << std::endl;
        tester();
        std::cout << std::endl;
    }

    return ( 0 );
}