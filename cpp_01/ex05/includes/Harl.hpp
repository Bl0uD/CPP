/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:28:04 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/16 17:06:34 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl
{
	public:
		Harl();
		~Harl();
		void	complain( std::string level );

	private:
		void	debug( void ) const;
		void	info( void ) const;
		void	warning( void ) const;
		void	error( void ) const;
};

#endif