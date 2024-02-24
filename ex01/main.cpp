#include "RPN.hpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
			throw std::runtime_error("Error: we need only 2 argv");
		RPN rpn(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (1);
}
