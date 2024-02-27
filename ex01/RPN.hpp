#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cstdlib>
#include <limits>
#include <string>
#include <iomanip>

class RPN
{
	private:
		std::stack<int> _rpn;

	public:
		RPN();
		RPN(std::string s);
		RPN(const RPN &autre);
		RPN &operator=(const RPN &autre);
		~RPN();

		void	doRPN(std::string s);
		void	parseArg(std::string s);
		int		calcul(int a, int b, std::string op);

		void	visualizeRPN();
		void	visualizeRPNCalcul(std::string op, int a, int b, int result);
};

#endif
