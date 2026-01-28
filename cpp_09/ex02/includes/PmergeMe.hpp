/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:08:03 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/28 19:08:06 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <exception>

class PmergeMe
{
	private:
		

	public:
		~PmergeMe();
		PmergeMe();
		PmergeMe(  );
		PmergeMe( const PmergeMe &copy );
		PmergeMe &operator=( const PmergeMe &instance );

		
};

#endif