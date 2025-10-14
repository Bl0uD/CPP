/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:58:06 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 16:13:24 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
	private:
	
	protected:
		std::string	type_;
	
	public:
		virtual ~Animal();
		Animal();
		Animal( std::string type );
		Animal( Animal const & other );
		Animal const & operator=( Animal const & copy );

		std::string getType( void ) const;
		virtual std::string	getName( void ) const;
		virtual void	makeSound( void ) const;
};

#endif
