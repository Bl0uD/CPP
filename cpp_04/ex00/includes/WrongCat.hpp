/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:03:00 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 16:21:54 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_HPP
# define WrongCat_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	private:

	protected:
		std::string	name_;
	
	public:
		~WrongCat();
		WrongCat();
		WrongCat( std::string name );
		WrongCat( WrongCat const & other );
		WrongCat const & operator=( WrongCat const & a );

		std::string	getName( void ) const;
		void	makeSound( void ) const;
};

#endif