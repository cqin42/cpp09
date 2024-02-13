/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Input.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <cqin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 16:42:34 by cqin              #+#    #+#             */
/*   Updated: 2024/02/13 18:00:06 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>

class Input
{
	public:
		Input(std::string str);
		~Input();
		void	setYear(int year);
		void	setMonth(int month);
		void	setDay(int day);
		int		getYear() const;
		int		getMonth() const;
		int		getDay() const;
		void	parseDate(std::string str);

	private:
		int		_year;
		int		_month;
		int		_day;
		int		_value;
		std::string		_input;
};

#endif
