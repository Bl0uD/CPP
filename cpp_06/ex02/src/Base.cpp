/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 17:06:14 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/09 17:33:16 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base::~Base( void )
{
	std::cout << "Base destructor called." << std::endl;
}

Base *generate( void )
{
	static bool seeded = false;
	if (!seeded) {
		srand(static_cast<unsigned int>(time(NULL)));
		seeded = true;
	}

	int i = rand() % 3;
	switch (i)
	{
		case 0: return new A();
		case 1: return new B();
		case 2: return new C();
		default: return ( NULL );
	}
}

void identify( Base *p )
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void identify( Base &p )
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	}
	catch(...){}

	try
	{
		B &b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	}
	catch(...){}

	try
	{
		C &c = dynamic_cast<C &>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	}
	catch(...)
	{
		std::cout << "unkown" << std::endl;
	}
}