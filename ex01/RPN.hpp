#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <deque>
#include <cstdlib>
#include <limits>

class RPN
{
	private:
		std::deque<int> _rpn;
		std::string sign;

	public:
		RPN();
		RPN(std::string s);
		RPN(const RPN &autre);
		RPN &operator=(const RPN &autre);
		~RPN();

		void	doRPN(std::string s);
		void	parseArg(std::string s);
		int	calcul(int a, int b, std::string op);
};

#endif
