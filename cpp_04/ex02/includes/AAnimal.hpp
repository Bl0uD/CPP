/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:58:06 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 17:48:15 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
# define AAnimal_HPP

# include <iostream>

class AAnimal
{
	private:
	
	protected:
		std::string	type_;
	
	public:
		virtual ~AAnimal();
		AAnimal();
		AAnimal( std::string type );
		AAnimal( AAnimal const & other );
		AAnimal const & operator=( AAnimal const & copy );

		std::string getType( void ) const;
		virtual std::string	getName( void ) const = 0;
		virtual void	makeSound( void ) const = 0;
};

#endif
