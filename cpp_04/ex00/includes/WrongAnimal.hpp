/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:58:06 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 16:21:23 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

# include <iostream>

class WrongAnimal
{
	private:
	
	protected:
		std::string	type_;
	
	public:
		virtual ~WrongAnimal();
		WrongAnimal();
		WrongAnimal( std::string type );
		WrongAnimal( WrongAnimal const & other );
		WrongAnimal const & operator=( WrongAnimal const & copy );

		std::string getType( void ) const;
		virtual std::string	getName( void ) const;
		virtual void	makeSound( void ) const;
};

#endif
