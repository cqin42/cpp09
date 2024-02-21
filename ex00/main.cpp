/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christine <christine@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:48:52 by cqin              #+#    #+#             */
/*   Updated: 2024/02/21 01:43:23 by christine        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <string>

void	parseArgv(int argc, char **argv)
{
	if (argc != 2)
		throw std::runtime_error("Error: could not open file.");
	std::fstream fileToread;
	std::fstream fileData;
	fileToread.open(argv[1], std::ios::in);
	fileData.open("data.csv", std::ios::in);
	if (!fileToread || !fileData)
	{
		fileToread.close();
		fileData.close();
		throw std::runtime_error("Error: could not open file.");
	}

	fileToread.close();
	fileData.close();
}

int	main(int argc, char **argv)
{
	try
	{
		parseArgv(argc, argv);
		std::string s = argv[1];
		BitcoinExchange btc(s);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
