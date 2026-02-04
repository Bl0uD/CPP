/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 19:08:08 by jdupuis           #+#    #+#             */
/*   Updated: 2026/01/31 10:59:30 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

PmergeMe::~PmergeMe( void ) {}

PmergeMe::PmergeMe( void ) {}

PmergeMe::PmergeMe( char **av )
{
    int i = 0;
    while( av[i] )
    {
        int value = std::atoi( av[i] );
		if ( value > 0 )
		{
			this->_before.push_back( value );
			this->_dequeStorage.push_back( value );
			this->_listStorage.push_back( value );
		}
		else
			throw InvalidInputException();
        i++;
    }
}

PmergeMe::PmergeMe( PmergeMe const &copy )
{
	*this = copy;
}

PmergeMe&PmergeMe::operator=( PmergeMe const &instance )
{
	if (this != &instance)
	{
		this->_before = instance._before;
		this->_dequeStorage = instance._dequeStorage;
		this->_listStorage = instance._listStorage;
		this->_timeDeque = instance._timeDeque;
		this->_timeList = instance._timeList;
	}
	return ( *this );
}

std::ostream &operator<<( std::ostream &os, const std::deque<int> &container )
{
    std::deque<int>::const_iterator it = container.begin();
    while ( it != container.end() )
    {
        os << *it;
        std::deque<int>::const_iterator next = it;
        if ( ++next != container.end() )
            os << " ";
        it++;
    }
    return ( os );
}

std::ostream &operator<<( std::ostream &os, const std::list<int> &container )
{
    std::list<int>::const_iterator it = container.begin();
    while ( it != container.end() )
    {
        os << *it;
        std::list<int>::const_iterator next = it;
        if ( ++next != container.end() )
            os << " ";
        it++;
    }
    return ( os );
}

static void generateJacobsthalNumbers( std::vector<size_t> &jacob, size_t max )
{
	jacob.push_back(0);
	jacob.push_back(1);
	size_t i = 2;
	while ( true )
	{
		size_t next = jacob[i - 1] + 2 * jacob[i - 2];
		if ( next > max )
			break;
		jacob.push_back( next );
		i++;
	}
}

static bool pairComparator( const std::pair<int, int> &a, const std::pair<int, int> &b )
{
	return a.second < b.second;
}

// ========== FORD-JOHNSON POUR DEQUE ==========
static void binaryInsertDeque( std::deque<int> &mainChain, int value, size_t endPos )
{
	size_t left = 0;
	size_t right = endPos;
	while ( left < right )
	{
		size_t mid = left + ( right - left ) / 2;
		if ( mainChain[mid] < value )
			left = mid + 1;
		else
			right = mid;
	}
	mainChain.insert( mainChain.begin() + left, value );
}

static void fordJohnsonDeque( std::deque<int> &container )
{
	if ( container.size() <= 1 )
		return;
	std::deque<std::pair<int, int> > pairs;
	int straggler = -1;
	bool hasStraggler = false;
	size_t i = 0;
	while ( i + 1 < container.size() )
	{
		int first = container[i];
		int second = container[i + 1];
		if ( first > second )
			pairs.push_back(std::make_pair( second, first ));
		else
			pairs.push_back(std::make_pair( first, second ));
		i += 2;
	}
	if ( container.size() % 2 == 1 )
	{
		straggler = container[container.size() - 1];
		hasStraggler = true;
	}
	size_t idx = 0;
	while ( idx < pairs.size() )
	{
		size_t j = idx + 1;
		while ( j < pairs.size() )
		{
			if ( pairs[idx].second > pairs[j].second )
			{
				std::pair<int, int> tmp = pairs[idx];
				pairs[idx] = pairs[j];
				pairs[j] = tmp;
			}
			++j;
		}
		++idx;
	}
	std::deque<int> mainChain;
	std::deque<int> pending;
	size_t k = 0;
	while ( k < pairs.size() )
	{
		mainChain.push_back( pairs[k].second );
		pending.push_back( pairs[k].first );
		++k;
	}
	if ( !pending.empty() )
	{
		mainChain.insert( mainChain.begin(), pending[0] );
		pending.erase( pending.begin() );
	}
	if ( !pending.empty() )
	{
		std::vector<size_t> jacobsthal;
		generateJacobsthalNumbers( jacobsthal, pending.size() );
		size_t lastIndex = 0;
		size_t i = 2;
		while ( i < jacobsthal.size() )
		{
			size_t currentJacob = jacobsthal[i];
			if ( currentJacob > pending.size() )
				currentJacob = pending.size();
			size_t j = currentJacob;
			while ( j > lastIndex )
			{
				size_t pendingIdx = j - 1;
				if ( pendingIdx < pending.size() )
				{
					size_t searchLimit = mainChain.size();
					binaryInsertDeque( mainChain, pending[pendingIdx], searchLimit );
				}
				--j;
			}
			lastIndex = currentJacob;
			++i;
		}
		size_t i2 = lastIndex;
		while ( i2 < pending.size() )
		{
			binaryInsertDeque( mainChain, pending[i2], mainChain.size() );
			++i2;
		}
	}
	if ( hasStraggler )
		binaryInsertDeque( mainChain, straggler, mainChain.size() );
	container = mainChain;
}

// ========== FORD-JOHNSON POUR LIST ==========
static void binaryInsertList( std::list<int> &mainChain, int value, size_t endPos )
{
	std::list<int>::iterator searchEnd = mainChain.begin();
	std::advance( searchEnd, std::min(endPos, mainChain.size()) );
	std::list<int>::iterator it = std::lower_bound( mainChain.begin(), searchEnd, value );
	mainChain.insert(it, value);
}

static void fordJohnsonList( std::list<int> &container )
{
	if ( container.size() <= 1 )
		return ;
	std::list<std::pair<int, int> > pairs;
	int straggler = -1;
	bool hasStraggler = false;
	std::list<int>::iterator it = container.begin();
	while ( it != container.end() )
	{
		int first = *it;
		++it;
		if ( it != container.end() )
		{
			int second = *it;
			++it;
			if ( first > second )
				pairs.push_back( std::make_pair(second, first) );
			else
				pairs.push_back( std::make_pair(first, second) );
		}
		else
		{
			straggler = first;
			hasStraggler = true;
		}
	}
	pairs.sort( pairComparator );
	std::list<int> mainChain;
	std::list<int> pending;
	std::list<std::pair<int, int> >::iterator pIt = pairs.begin();
	while ( pIt != pairs.end() )
	{
		mainChain.push_back( pIt->second );
		pending.push_back( pIt->first );
		++pIt;
	}
	if ( !pending.empty() )
	{
		mainChain.push_front( pending.front() );
		pending.pop_front();
	}
	if ( !pending.empty() )
	{
		std::vector<size_t> jacobsthal;
		generateJacobsthalNumbers( jacobsthal, pending.size() );
		size_t lastIndex = 0;
		size_t i = 2;
		while ( i < jacobsthal.size() )
		{
			size_t currentJacob = jacobsthal[i];
			if ( currentJacob > pending.size() )
				currentJacob = pending.size();
			size_t j = currentJacob;
			while ( j > lastIndex )
			{
				size_t pendingIdx = j - 1;
				if ( pendingIdx < pending.size() )
				{
					std::list<int>::iterator pendIt = pending.begin();
					std::advance( pendIt, pendingIdx );
					size_t searchLimit = mainChain.size();
					binaryInsertList( mainChain, *pendIt, searchLimit );
				}
				--j;
			}
			lastIndex = currentJacob;
			++i;
		}
		std::list<int>::iterator pendIt = pending.begin();
		std::advance( pendIt, lastIndex );
		while ( pendIt != pending.end() )
		{
			binaryInsertList( mainChain, *pendIt, mainChain.size() );
			++pendIt;
		}
	}
	if ( hasStraggler )
		binaryInsertList( mainChain, straggler, mainChain.size() );
	container = mainChain;
}

void	PmergeMe::print()
{
	std::cout << "Before: " << _before << std::endl;
	std::cout << "After:  " << _dequeStorage << std::endl;
	std::cout << "Time to process a range of " << _dequeStorage.size() 
			<< " elements with std::deque : " << _timeDeque << " us" << std::endl;
	std::cout << "Time to process a range of " << _listStorage.size() 
			<< " elements with std::list  : " << _timeList << " us" << std::endl;
}

void	PmergeMe::execute()
{
	clock_t start = clock();
	fordJohnsonDeque( this->_dequeStorage );
	this->_timeDeque = static_cast<double>( clock() - start ) * 1000000 / CLOCKS_PER_SEC;

	start = clock();
	fordJohnsonList( this->_listStorage );
	this->_timeList = static_cast<double>( clock() - start ) * 1000000 / CLOCKS_PER_SEC;

	this->print();
}
