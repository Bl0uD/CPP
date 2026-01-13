/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 16:23:04 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/13 15:21:36 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_CLASS_H
# define DATA_CLASS_H
# include <iostream>

struct Data
{
		int			x;
		int			y;
		int			z;
		std::string id;
		std::string seed;
		std::string password;
};

#endif