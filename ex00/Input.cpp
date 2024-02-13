/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <cqin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:50:28 by cqin              #+#    #+#             */
/*   Updated: 2024/02/13 18:15:56 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Input.hpp"

Input::Input(std::string str)
{
	size_t pos = 0;
	// std::cout << str << std::endl;
	pos = str.find('|', pos);
	// std::cout << pos << std::endl;
	if (pos != std::string::npos)
	{
		// std::cout << str.substr(0, pos - 1) << "." << std::endl;
		// std::cout << str.substr(pos + 2, str.size() - (pos + 1)) << "." << std::endl;
		parseDate(str.substr(0, pos - 1));
		std::string value = str.substr(pos + 2, str.size() - (pos + 1));
		int n = 0;
		for (int i = 0; i < value.size(); i++)
		{
			if (!isdigit(value[i]) && i == 0 && (value[i] == '-' || value[i] == '+'))
				;
			else if (value[i] == '.' && n < 1)
				n++;
			else if (!isdigit(value[i]))
				throw std::runtime_error("Error: value not correct");
		}

		n = atoi(value.c_str());
		if (n < 0)
			throw std::runtime_error("Error: not a positive number.");
		else if (n > 1000)
			throw std::runtime_error("Error: too large a number.");

	}




	parseDate(str);

}


Input::~Input()
{}

void	Input::setYear(int year)
{
	_year = year;
}
void	Input::setMonth(int month)
{
	_month = month;
}

void	Input::setDay(int day)
{
	_day = day;
}

int	Input::getYear() const
{
	return (_year);
}

int	Input::getMonth() const
{
	return (_month);
}

int	Input::getDay() const
{
	return (_day);
}

void	parseYear(std::string year)
{
	int sub = atoi((year.substr(0, 4)).c_str());

	try
	{
		if (sub < 0)
			throw std::runtime_error("Error: Not a positive number.");
		else if (sub > 9999)
			throw std::runtime_error("Error: too large number.");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	parseMonth(std::string month)
{
	int sub = atoi((month.substr(0, 4)).c_str());

	try
	{
		if (sub < 0)
			throw std::runtime_error("Error: Not a positive number.");
		else if (sub > 12)
			throw std::runtime_error("Error: too large number.");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	parseDay(std::string day)
{
	int sub = atoi((day.substr(0, 4)).c_str());

	try
	{
		if (sub < 1)
			throw std::runtime_error("Error: Not a positive number.");
		else if (sub > 31)
			throw std::runtime_error("Error: too large number.");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	Input::parseDate(std::string str)
{
	try
	{
		if (str.size() != 11)
			throw std::runtime_error("Syntax of date is not correct");
		for (int i = 0; i < str.size(); i++)
		{
			if (str[i] == '-' && (i == 4 || i == 7))
				;
			else if (isdigit(str[i]))
				;
			else
				throw std::runtime_error("Date is not a digit");
		}

		try
		{
			parseYear(str.substr(0, 4));
			parseMonth(str.substr(5, 2));
			parseDay(str.substr(9, 2));
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
