/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <cqin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:48:52 by cqin              #+#    #+#             */
/*   Updated: 2024/02/13 18:29:05 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "Input.hpp"
#include <string>


// void	readFile(std::fstream &fileToRead)
// {
// 	std::string s;
// 	while (getline(fileToRead, s))
// 	{
// 		Input input(s);
// 	}
// }

void	parseArgv(int argc, char **argv)
{
	if (argc != 2)
		throw std::runtime_error("Error: could not open file.");
	std::fstream fileToread;
	fileToread.open(argv[1], std::ios::in);
	if (!fileToread)
		throw std::runtime_error("Error: could not open file.");

	std::string s;
	while (getline(fileToread, s))
	{
		Input input(s);
	}
	fileToread.close();
}

int	main(int argc, char **argv)
{
	try
	{
		parseArgv(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
