/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <cqin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:49:26 by cqin              #+#    #+#             */
/*   Updated: 2024/02/13 16:46:32 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>
#include <fstream>

// template<typename T>
// void	dateFormat(T date)
// {
// 	if (date.size() != 10)
// 		throw std::runtime_error("Date not in format");
// 	for (int i = 0; i < date.size(); i++)
// 	{
// 		if (date[i] == '-' && (i == 4 || i == 7))
// 			;
// 		else if (!isdigit(date[i]))
// 			throw std::runtime_error("Date is not a digit");
// 	}

// 	int sub = atoi(date.substr(0, 4));

// 	try
// 	{
// 		if (sub < 0)
// 			throw std::runtime_error("Error: Not a positive number.");
// 		else if (sub > 9999)
// 			throw std::runtime_error("Error: too large number.");
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// }

// template<typename T>
// void	valueFormat(T value)
// {
// 	for (int i = 0; i < value.size(); i++)
// 	{
// 		if (!isdigit(value[i]))
// 			throw std::runtime_error("Value is not a digit");
// 	}
// 	if (value < 0 || value > 1000)
// 		throw std::runtime_error("Value out of bonds");
// }

#endif
