#include "PmergeMe.hpp"

bool	isDigit(char *arg)
{
	for (int i = 0; arg[i]; i++)
	{
		if (!isdigit(arg[i]))
			return (false);
	}
	// long n = atol(arg);
	if (atol(arg) > std::numeric_limits<int>::max())
		throw std::runtime_error("Error: only integer");
	return (true);
}

void	parsing(int argc, char **argv)
{
	std::vector<unsigned int> vector;
	std::list<unsigned int> list;
	for (int i = 1; i < argc; i++)
	{
		if (isDigit(argv[i]) == false)
			throw std::runtime_error("Error: only positive integer");
		vector.push_back(atoi(argv[i]));
		list.push_back(atoi(argv[i]));
	}
	hasDuplicate(vector);
	// printSequence(vector, "Before");
	// printSequence(vector, "Before");
	// mergeInsertSortProgram(vector, "vector");
	// // printSequence(vector, "After");
	// mergeInsertSortProgram(list, "list");
}

int main(int argc, char **argv)
{
	try
	{
		if (argc < 2)
			throw std::runtime_error("Error");
		parsing(argc, argv);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

}
