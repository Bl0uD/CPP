/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:02:52 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 17:30:10 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain* _brain;

	protected:
		std::string	name_;
	
	public:
		~Dog();
		Dog();
		Dog( std::string name );
		Dog( Dog const & other );
		Dog const & operator=( Dog const & copy );

		std::string	getName( void ) const;
		void	makeSound( void ) const;
};

#endif