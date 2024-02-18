#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange():_data(), _inputFile("")
{}

BitcoinExchange::BitcoinExchange(std::string inputFile):_data(), _inputFile(inputFile)
{
	setData();
	// std::cout << _data[2011-01-01] << std::endl;
	readInputFile();
}

// BitcoinExchange::BitcoinExchange(const BitcoinExchange &autre)
// {}

// BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &autre)
// {}


BitcoinExchange::~BitcoinExchange()
{}

void	BitcoinExchange::parseDate(std::string date)
{
	int year;
	int month;
	int day;

	year = atoi(date.substr(0, 4).c_str());
	month = atoi(date.substr(5, 2).c_str());
	day = atoi(date.substr(8, 2).c_str());

	if (year > 9999 || year < 1000)
		throw std::runtime_error("Error: bad year " + date);
	if (month < 1 || month > 12)
		throw std::runtime_error("Error: bad month " + date);
	if ((month < 8 && month % 2 != 0) || (month > 7 && month % 2 == 0))
	{
		// std::cout << here <<
		if (day > 31 || day < 1)
			throw std::runtime_error("Error: bad day " + date);
	}
	else
	{
		if (month == 2 && (day > 28 || day < 1))
			throw std::runtime_error("Error: bad day " + date);
		else if (day > 30 || day < 1)
			throw std::runtime_error("Error: bad day " + date);
	}
	// std::cout << year << " " << month << " " << day << std::endl;
}

void	BitcoinExchange::parseValue(std::string date, std::string value)
{

	double val = atof(value.substr(0, value.size()).c_str());
	if (val > 1000)
		throw std::runtime_error("Error: too large a number.");
	else if (val < 0)
	{
		// std::cout << "here" << std::endl;
		throw std::runtime_error("Error: not a positive number.");
	}
	std::map<std::string, double>::const_iterator it = _data.find(date);
	if (it != _data.end())
		std::cout << date << " => " << val << " = " << (val * it->second ) << std::endl;
	else
	{
		it = _data.lower_bound(date);
		if (it != _data.begin())
			--it;
		std::cout << date << " => " << val << " = " << (val * it->second ) << std::endl;
	}
}

void	BitcoinExchange::parseLine(std::string line)
{
	int dot = 0;
	std::string date;
	for (size_t i = 0; i < line.size(); i++)
	{
		if ((i == 4 || i == 7) && line[i] == '-')
			;
		else if (i == 10 && line[i] == ',')
		{
			date = line.substr(0, i);
			parseDate(date);
		}
		else if (i > 10 && line[i] == '.' && dot == 0)
			dot++;
		else if (!isdigit(line[i]))
		{
			std::cout << line[i] << std::endl;
			throw std::runtime_error("Error: bad input for data.csv, cannot continue ");
		}
		else if (i == line.size() - 1)
		{
			double value = atof(line.substr(11, line.size() - 11).c_str());
			_data[date] = value;
		}
			// parseValue(line.substr(11, line.size() - 11));
	}
}

void	BitcoinExchange::setData()
{
	std::fstream dataFile;

	dataFile.open("data.csv", std::ios::in);
	if (!dataFile)
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	getline(dataFile, line);
	// size_t	pos;
	while (getline(dataFile, line))
	{
		parseLine(line);
	}
}

void	BitcoinExchange::checkLine(std::string line)
{
	int dot = 0;
	std::string date;

	if (line.size() < 14)
		throw std::runtime_error("Error: bad input => " + line);

	for (size_t i = 0; i < line.size(); i++)
	{
		if ((i == 4 || i == 7) && line[i] == '-')
			;
		else if ((i == 10 || i == 12) && line[i] == ' ')
			;
		else if (i == 11 && line[i] == '|')
		{
			date = line.substr(0, i - 1);
			parseDate(date);
		}
		else if (i > 10 && line[i] == '.' && dot == 0)
			dot++;
		else if (line[i] != '-' && !isdigit(line[i]))
		{
			// std::cout << i << std::endl;
			// std::cout << "hahaha = " << line[i] << std::endl;
			throw std::runtime_error("Error: bad input line");
		}
		else if (i == line.size() - 1)
		{
			parseValue(date, line.substr(13, line.size() - 11));
			// int value = atoi(line.substr(11, line.size() - 11).c_str());
		}
	}
}

void	BitcoinExchange::readInputFile()
{
	std::fstream file;
	file.open(_inputFile.c_str(), std::ios::in);
	if (!file)
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	getline(file, line);
	// std::cout << line << std::endl;
	if (line != "date | value")
		throw std::runtime_error("Error: bad format");
	while (getline(file, line))
	{
		try
		{
			checkLine(line);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}
