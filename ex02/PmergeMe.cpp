#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{}

PmergeMe::PmergeMe(int argc, char **argv)
{
	mergeInsertSort(argc, argv);
}

PmergeMe::PmergeMe(const PmergeMe &autre)
{
	(void)autre;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &autre)
{
	(void) autre;
	return *this;
}

PmergeMe::~PmergeMe()
{}

void	PmergeMe::sortPairs(std::vector<std::pair<unsigned int, unsigned int> > &pairs)
{
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (pairs[i].first > pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	}
}

void	PmergeMe::sortLargerValue(std::vector<std::pair<unsigned int, unsigned int> > &pairs, int n)
{
	if (n < 2)
		return ;

	sortLargerValue(pairs, n - 1);
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if (i + 1 == pairs.size())
		;
			// std::cout << "here" << std::endl;
		else if (pairs[i].first > pairs[i + 1].first)
			std::swap(pairs[i], pairs[i + 1]);
	}

	/**/
	for (size_t i = 0; i < pairs.size(); i++)
	{
		std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
	}
	std::cout << std::endl;
	/**/
}



void	PmergeMe::mergeInsertSort(int argc, char **argv)
{
	int	hasStraggler = (argc - 1) % 2 != 0;

	if (hasStraggler)
		hasStraggler = atoi(argv[argc - 1]);
	else
		hasStraggler = -1;

	std::vector<std::pair<unsigned int, unsigned int> > pairs;
	if (hasStraggler > 0) argc -= 1;
	for (int i = 1; i < argc - 1; i += 2)
	{
		int a = atoi(argv[i]);
		int b = atoi(argv[i + 1]);
		pairs.push_back(std::make_pair(a, b));
	}

	sortPairs(pairs);
	sortLargerValue(pairs, pairs.size());

	// for (size_t i = 0; i < pairs.size(); i++)
	// {
	// 	std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
	// 	// if (pairs[i].first > pairs[i].second)
	// 	// 	std::swap(pairs[i].first, pairs[i].second);
	// }

}
