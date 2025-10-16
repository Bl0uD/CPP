/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdupuis <jdupuis@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 18:26:41 by jdupuis           #+#    #+#             */
/*   Updated: 2025/10/16 17:05:51 by jdupuis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <filesystem>
#include <sys/stat.h>

bool	checkFile( std::string filename )
{
	struct	stat info;

	if ( stat(filename.c_str(), &info) )
		return ( std::cout << "File inexistant.." << std::endl, false );
	if ( info.st_mode & S_IFDIR )
		return ( std::cout << "The 'file' is a directory.." << std::endl, false );
	return (true);
}

void	readFile( std::string filename, std::string *tmpFile )
{
	std::ifstream fileIn;
	char		c;
	
	fileIn.open(filename.c_str());
	while (1)
	{
		if (!fileIn.get(c))
			break;
		*(tmpFile) += c;
	}
	fileIn.close();
}

bool	searchStr( std::string replaced, std::string replaceby, int replaced_length, std::string *tmpFile )
{
	std::size_t	i = 0;
	bool		is_found = false;

	while((i = tmpFile->find(replaced, i)), i != std::string::npos)
	{
		tmpFile->erase(i, replaced_length);
		tmpFile->insert(i, replaceby);
		i += replaceby.length();
		is_found = true;
	}
	if ( is_found )
		return ( true );
	return ( false );
}

bool	writeFile( std::string filename, std::string *tmpFile )
{
	std::ofstream fileOut;
	
	fileOut.open((filename + ".replace").c_str());
	if (!fileOut.good())
	{
		std::cout << "can't create file" << std::endl;
		return ( false );
	}

	fileOut << *(tmpFile) << std::endl;
	fileOut.close();
	return ( true );
}

int	main( int ac, char **av )
{
	if ( ac != 4 )
		return ( std::cout << "wrong argument, need : [filename] [str to replace] [replaced by]" << std::endl, 1 );
	std::string	filename = av[1];
	std::string	replaced = av[2];
	std::string	replaceby = av[3];
	std::string	tmpFile;
	int			replaced_length = replaced.length();

	if ( !checkFile(filename) )
		return ( 1 );
	readFile( filename, &tmpFile );
	if ( !searchStr( replaced, replaceby, replaced_length, &tmpFile ) )
	{
		std::cout << "not match in file" << std::endl;
		return (1);
	}
	if ( !writeFile( filename, &tmpFile ) )
		return ( 1 );
	return (0);
}
