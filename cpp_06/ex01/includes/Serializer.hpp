/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 15:59:52 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/09 16:31:32 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <stdint.h>
# include "Data.hpp"

class Serializer
{
	private:
		~Serializer();
		Serializer();
		Serializer( std::string );
		Serializer( Serializer const &copy );
		Serializer &operator=( Serializer const &instance );

	public:
		static uintptr_t serialize( Data *ptr );
		static Data* deserialize( uintptr_t raw );
};

#endif