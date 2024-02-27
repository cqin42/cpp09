#include "RPN.hpp"


RPN::RPN():_rpn()
{}

RPN::RPN(std::string s):_rpn()
{
	doRPN(s);
}

RPN::RPN(const RPN &autre):_rpn(autre._rpn)
{
}

RPN &RPN::operator=(const RPN &autre)
{
	if (this != &autre)
	{
		_rpn = autre._rpn;
	}
	return (*this);
}


RPN::~RPN()
{
}

void	RPN::visualizeRPN()
{
	// int		idx = 0;
	std::stack<int> copy = _rpn;
	std::cout << "\033[1;4;30mVisualizer RPN\033[0m" << std::endl;
	while (!copy.empty())
	{
		// std::cout << std::setw(2) << idx++ << " | ";
		std::cout << std::setw(2) << copy.top() << std::endl;
		copy.pop();
	}
	std::cout << std::endl;
}

void	RPN::visualizeRPNCalcul(std::string op, int a, int b, int result)
{
	// std::cout << "aaa" << std::endl;
	std::stack<int> copy = _rpn;
	std::cout << "\033[1;4;30mVisualizer RPN\033[0m" << std::endl;
	if (copy.empty())
	{
		std::cout << std::setw(2) << result << " = " << a << " " << op << " " << b << std::endl;
	}
	while (!copy.empty())
	{
		std::cout << result << " = " << a << " " << op << " " << b << std::endl;
		std::cout << std::setw(2) << copy.top() << std::endl;
		copy.pop();
	}
	std::cout << std::endl;
}

int	RPN::calcul(int a, int b, std::string op)
{
	long long result = 0;
	if (op == "+")
	{
		result = static_cast<long long> (a) + static_cast<long long> (b);
		visualizeRPNCalcul(op, a, b, result);
		// std::cout << a << " + " << b << " = " << result <<std::endl;
	}
	else if ( op == "-")
	{
		result = static_cast<long long> (a) - static_cast<long long> (b);
		visualizeRPNCalcul(op, a, b, result);
		// std::cout << a << " - " << b << " = " << result <<std::endl;
	}
	else if (op == "/")
	{
		if (b == 0)
			throw std::runtime_error("Error: division by 0");
		result = static_cast<long long> (a) / static_cast<long long> (b);
		visualizeRPNCalcul(op, a, b, result);
		// std::cout << a << " / " << b << " = " << result <<std::endl;
	}
	else if (op == "*")
	{
		result = static_cast<long long> (a) * static_cast<long long> (b);
		visualizeRPNCalcul(op, a, b, result);
		// std::cout << a << " * " << b << " = " << result <<std::endl;
	}

	if (result <= std::numeric_limits<int>::min() || result > std::numeric_limits<int>::max())
			throw std::runtime_error("Error: int min or max reached");
	// visualizeRPN();
	return (static_cast<int>(result));
}

void	RPN::parseArg(std::string s)
{
	int a;
	int b;

	if (s.size() == 2 && (s[0] == '+' || s[0] == '-') && isdigit(s[1]))
	{
		a = atoi(s.c_str());
		_rpn.push(a);
	}
	else if (s == "+" || s == "-" || s == "/" || s == "*")
	{
		if (_rpn.size() < 2)
			throw std::runtime_error("Error: not enough operands");
		b = _rpn.top();
		_rpn.pop();
		a = _rpn.top();
		_rpn.pop();
		_rpn.push(calcul(a, b, s));
	}
	else if (s.size() != 1 || !isdigit(s[0]))
	{
		throw std::runtime_error("Error");
	}
	else if (s.size() == 1 && isdigit(s[0]))
	{
		a = atoi(s.c_str());
		_rpn.push(a);
	}
	visualizeRPN();
}

void	RPN::doRPN(std::string s)
{
	int start = 0;

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
	start = _rpn.top();
	std::cout << "Result " << start << std::endl;
}
