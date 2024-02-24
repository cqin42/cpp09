#include "RPN.hpp"


RPN::RPN():_rpn(), sign("+")
{}

RPN::RPN(std::string s):_rpn(), sign("+")
{
	doRPN(s);
}

// RPN::RPN(const RPN &autre)
// {
// }

// RPN &RPN::operator=(const RPN &autre)
// {
// }


RPN::~RPN()
{
}

int	RPN::calcul(int a, int b, std::string op)
{
	long long result = 0;

	if (op == "+")
	{
		result = static_cast<long long> (a) + static_cast<long long> (b);
	}
	else if ( op == "-")
	{
		result = static_cast<long long> (a) - static_cast<long long> (b);
	}
	else if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Error: division by 0");
		result = static_cast<long long> (a) / static_cast<long long> (b);
	}
	else if (op == "*")
	{
		result = static_cast<long long> (a) * static_cast<long long> (b);
	}

	// strtol(str.c_str(), &endptr, 10)
	// std::cout << std::numeric_limits<int>::max() << std::endl;
	if (result <= std::numeric_limits<int>::min() || result > std::numeric_limits<int>::max())
			throw std::runtime_error("Error: int min or max reached");
	return (static_cast<int>(result));
}

void	RPN::parseArg(std::string s)
{
	int a;
	int b;

	// std::cout << s.size() << " lalala " << s << std::endl;
	if (s.size() == 2 && (s[0] == '+' || s[0] == '-') && isdigit(s[1]))
	{
		// if (atof(s.c_str()) <= std::numeric_limits<int>::min())
		// 	throw std::runtime_error("Error: int min reached");
		a = atoi(s.c_str());
		_rpn.push_back(a);
	}
	else if (s == "+" || s == "-" || s == "/" || s == "*")
	{
		// std::cout << "here " << s << std::endl;
		if (_rpn.size() < 2)
			throw std::runtime_error("Error: not enough operands");
		b = _rpn.back();
		_rpn.pop_back();
		a = _rpn.back();
		_rpn.pop_back();
		_rpn.push_back(calcul(a, b, s));
	}
	else if (s.size() != 1 || !isdigit(s[0]))
	{
		throw std::runtime_error("Error");
	}
	else if (s.size() == 1 && isdigit(s[0]))
	{
		// std::cout << "here" << std::endl;
		// if (atof(s.c_str()) > std::numeric_limits<int>::max())
		// 	throw std::runtime_error("Error: value max reached");
		a = atoi(s.c_str());
		_rpn.push_back(a);
	}
}

void	RPN::doRPN(std::string s)
{
	int start = 0;
	// std::cout << s << std::endl;
	for (size_t i = 0; i <= s.size(); i++)
	{
		if (s[i] == ' ' || i == s.size())
		{
			std::string arg;

			parseArg(s.substr(start, i - start));
			start = i + 1;
		}
	}
	if (_rpn.size() != 1)
		throw std::runtime_error("Error: incorrect input");
	start = _rpn.back();
	std::cout << "Result " << start << std::endl;
}
