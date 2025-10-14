/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:56:54 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 17:36:54 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"

int    main( void )
{
    const Animal *tab[10];
    int    i = 0;

    while (i < 10)
    {
        if (!(i % 2))
            tab[i] = new Cat();
        else
            tab[i] = new Dog();
        i++;
        std::cout << std::endl;
    }

    std::cout << std::endl << std::endl;

    i = 0;
    while (i < 10)
    {
        delete(tab[i]);
        i++;
        std::cout << std::endl;
    }
	return (0);
}