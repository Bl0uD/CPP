/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:03:00 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 17:30:05 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
	private:
		Brain* _brain;

	protected:
		std::string	name_;
	
	public:
		~Cat();
		Cat();
		Cat( std::string name );
		Cat( Cat const & other );
		Cat const & operator=( Cat const & a );

		std::string	getName( void ) const;
		void	makeSound( void ) const;
};

#endif