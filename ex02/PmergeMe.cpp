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

void	PmergeMe::FMJI(std::vector<std::pair<unsigned int, unsigned int> > &pairs, int straggler)
{
	std::vector<unsigned int> s, pend;

	// std::cout << "<<<<<<<<" << std::endl;
	for (std::vector<std::pair<unsigned int, unsigned int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		s.push_back(it->first);
    	pend.push_back(it->second);
   		// std::cout << it->first << std::endl;
    	// std::cout << it->second << std::endl;
	}

	if (straggler != -1)
		pend.push_back(straggler);

	insertRemainingElements(s, pend);
}


void PmergeMe::insertRemainingElements(std::vector<unsigned int> &s, const std::vector<unsigned int> &remainingElements)
{
    for (size_t i = 0; i < remainingElements.size(); ++i)
	{
        unsigned int elementToInsert = remainingElements[i];
        size_t insertionIndex = binarySearchInsertionIndex(s, elementToInsert);
        s.insert(s.begin() + insertionIndex, elementToInsert);
    }
	for (size_t i = 0; i < s.size(); i++)
	{
		std::cout << s[i] << " ";
	}
	std::cout << std::endl;
}

size_t PmergeMe::binarySearchInsertionIndex(const std::vector<unsigned int> &s, unsigned int element)
{
    size_t low = 0;
    size_t high = s.size();
    while (low < high)
	{
        size_t mid = low + (high - low) / 2;
        if (s[mid] < element)
            low = mid + 1;
		else
            high = mid;
    }
    return (low);
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

	// for (size_t i = 0; i < pairs.size(); i++)
	// {
	// 	std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
	// 	// if (pairs[i].first > pairs[i].second)
	// 	// 	std::swap(pairs[i].first, pairs[i].second);
	// }
	// std::cout << std::endl;

	sortPairs(pairs);
	sortLargerValue(pairs, pairs.size());
	// for (size_t i = 0; i < pairs.size(); i++)
	// {
	// 	std::cout << pairs[i].first << " " << pairs[i].second << std::endl;
	// 	// if (pairs[i].first > pairs[i].second)
	// 	// 	std::swap(pairs[i].first, pairs[i].second);
	// }
	FMJI(pairs, hasStraggler);


}
