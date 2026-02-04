/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 14:03:20 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/31 10:52:26 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <list>
# include <sys/time.h>
# include <ctime>
# include <algorithm>
# include <iterator>
# include <cstdlib>

class PmergeMe
{
	private:
		std::deque<int>	_before;
		std::deque<int>	_dequeStorage;
		std::list<int>	_listStorage;
		double			_timeDeque;
		double			_timeList;

	public:
		PmergeMe();
		PmergeMe( char **av );
		PmergeMe( const PmergeMe &copy );
		PmergeMe &operator=( const PmergeMe &instance );
		~PmergeMe();

		void execute();
		void print();

	class InvalidInputException : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return ( "Error" );
			}	
	};
};

std::ostream &operator<<( std::ostream &os, const std::deque<int> &container );
std::ostream &operator<<( std::ostream &os, const std::list<int> &container );

#endif