/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:02:52 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 17:49:21 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal
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