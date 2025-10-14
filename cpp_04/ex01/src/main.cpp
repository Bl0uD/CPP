/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:56:54 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 16:37:59 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"

int	main( void )
{
	const Animal* meta = new Animal();
	const Animal* Sally = new Dog("Sally");
	const Animal* Kiwi = new Cat("Kiwi");
	const WrongAnimal* WrongKiwi = new WrongCat("WrongKiwi");

	std::cout << Sally->getName() << " is a " << Sally->getType() << " ! ";
	Sally->makeSound();
	std::cout << std::endl;
	std::cout << Kiwi->getName() << " is a " << Kiwi->getType() << " ! ";
	Kiwi->makeSound(); //will output the cat sound!
	std::cout << std::endl;
	meta->makeSound();

	std::cout << WrongKiwi->getName() << " is a " << WrongKiwi->getType() << " ! ";
	WrongKiwi->makeSound();
	
	delete ( meta );
	delete ( Sally );
	delete ( Kiwi );
	delete ( WrongKiwi );

	return (0);
}
