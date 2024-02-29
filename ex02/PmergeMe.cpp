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
		else if (pairs[i].first > pairs[i + 1].first)
			std::swap(pairs[i], pairs[i + 1]);
	}
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

	insertPend(s, pend);
}


void PmergeMe::insertPend(std::vector<unsigned int> &s, const std::vector<unsigned int> &pend)
{
    for (size_t i = 0; i < pend.size(); ++i)
	{
        unsigned int elementToInsert = pend[i];
        size_t insertionIndex = binarySearchInsertionIndex(s, elementToInsert);
        s.insert(s.begin() + insertionIndex, elementToInsert);
    }

	std::cout << "After: ";
	for (size_t i = 0; i < s.size(); i++)
		std::cout << s[i] << " ";
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
	clock_t startTime = std::clock();
	int	hasStraggler = (argc - 1) % 2 != 0;

	if (hasStraggler)
		hasStraggler = atoi(argv[argc - 1]);
	else
		hasStraggler = -1;

	std::vector<std::pair<unsigned int, unsigned int> > pairs;
	std::list<std::pair<unsigned int, unsigned int> > list;
	if (hasStraggler > 0) argc -= 1;
	for (int i = 1; i < argc - 1; i += 2)
	{
		int a = atoi(argv[i]);
		int b = atoi(argv[i + 1]);
		pairs.push_back(std::make_pair(a, b));
		list.push_back(std::make_pair(a, b));
	}
	clock_t end1 = std::clock();
	startTime = static_cast<double>(end1 - startTime);
	hasDuplicate(pairs, hasStraggler);
	// printSort(pairs, "Before :");
	end1 = std::clock();
	sortPairs(pairs);
	sortLargerValue(pairs, pairs.size());
	FMJI(pairs, hasStraggler);
	// clock_t end = std::clock();

	std::cout << std::fixed;
	std::cout << (startTime + static_cast<double>(std::clock() - end1)/ static_cast<double>(CLOCKS_PER_SEC)) * 1000000 << " us" << std::endl;

	end1 = std::clock();
	sortPairsList(list);
	sortLargerValueList(list, list.size());
	FMJIlist(list, hasStraggler);
	std::cout << std::fixed;
	std::cout << (startTime + static_cast<double>(std::clock() - end1)/ static_cast<double>(CLOCKS_PER_SEC)) * 1000000 << " us" << std::endl;

}
/*--------------------------------------------------------------------------------------------------------------------------*/

void	PmergeMe::sortPairsList(std::list<std::pair<unsigned int, unsigned int> > &pairs)
{
	for (std::list<std::pair<unsigned int, unsigned int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
}

void	PmergeMe::sortLargerValueList(std::list<std::pair<unsigned int, unsigned int> > &pairs, int n)
{
	if (n < 2)
		return ;

	sortLargerValueList(pairs, n - 1);
	for (std::list<std::pair<unsigned int, unsigned int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		std::list<std::pair<unsigned int, unsigned int> >::iterator ite = it;
		ite++;
		if (ite == pairs.end())
			;
		else if (it->first > ite->first)
			std::swap(it, ite);
	}
}

void	PmergeMe::FMJIlist(std::list<std::pair<unsigned int, unsigned int> > &pairs, int straggler)
{
	std::list<unsigned int> s, pend;

	// std::cout << "<<<<<<<<" << std::endl;
	for (std::list<std::pair<unsigned int, unsigned int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
	{
		s.push_back(it->first);
    	pend.push_back(it->second);
   		// std::cout << it->first << std::endl;
    	// std::cout << it->second << std::endl;
	}

	if (straggler != -1)
		pend.push_back(straggler);

	insertPendList(s, pend);
}


void PmergeMe::insertPendList(std::list<unsigned int> &s, const std::list<unsigned int> &pend)
{
	for (std::list<unsigned int>::const_iterator it = pend.begin(); it != pend.end(); it++)
	{
        unsigned int elementToInsert = *it;
        std::list<unsigned int>::iterator insertionIndex = binarySearchInsertionIndexList(s, elementToInsert);
        s.insert(insertionIndex, elementToInsert);
    }
	std::cout << "After: ";
	for (std::list<unsigned int>::const_iterator it = s.begin(); it != s.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

std::list<unsigned int>::iterator PmergeMe::binarySearchInsertionIndexList(std::list<unsigned int> &s, unsigned int element)
{
    std::list<unsigned int>::iterator low = s.begin();
    std::list<unsigned int>::iterator high = s.end();
    while (low != high)
	{
		std::list<unsigned int>::iterator mid = low;
		std::advance(mid, std::distance(low, high) / 2);
        if (*mid < element)
            ++low;
        else
            high = mid;
    }
    return (low);
}
