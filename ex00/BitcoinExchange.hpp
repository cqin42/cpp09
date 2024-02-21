/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christine <christine@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:49:26 by cqin              #+#    #+#             */
/*   Updated: 2024/02/21 01:29:09 by christine        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <cstdlib>
#include <cmath>


class BitcoinExchange
{
	private:
		std::map<std::string, double> _data;
		std::string	_inputFile;
		BitcoinExchange();
	public:
		BitcoinExchange(std::string inputFile);
		BitcoinExchange(const BitcoinExchange &autre);
		BitcoinExchange &operator=(const BitcoinExchange &autre);
		~BitcoinExchange();

		void	parseValue(std::string date, std::string value);
		void	checkLine(std::string line);
		void	readInputFile();

		void	parseDate(std::string date);
		void	parseLine(std::string line);
		void	setData();
};


#endif
