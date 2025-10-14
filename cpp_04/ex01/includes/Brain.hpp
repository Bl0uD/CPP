/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:52:25 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/14 17:30:57 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string	_ideas[100];
		Brain( std::string );
	
	protected:
	
	public:
		~Brain();
		Brain();
		Brain( Brain const & copy );
		Brain const & operator=( Brain const & instance );
};

#endif
