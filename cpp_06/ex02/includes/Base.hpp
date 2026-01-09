/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:59:14 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/09 17:33:40 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <string>
# include <cstdlib>

class Base
{
	public:
		virtual ~Base() = 0;

};
	
Base *generate(void);
void identify(Base *p);
void identify(Base &p);

#endif