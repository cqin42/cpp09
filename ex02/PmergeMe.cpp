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
   		// std::cout << it->first ;
    	// std::cout << it->second << std::endl;
	}

	if (straggler != -1)
		pend.push_back(straggler);

	insertPend(s, pend);
}


void PmergeMe::insertPend(std::vector<unsigned int> &s, const std::vector<unsigned int> &pend)
{
	std::vector<unsigned int>::const_iterator it = pend.begin();
	// std::cout << *it << std::endl;
    for (it == pend.begin(); it != pend.end(); it++)
	{
        unsigned int elementToInsert = *it;
        std::vector<unsigned int>::iterator insertionIndex = binarySearchInsertionIndex(s, elementToInsert);
        s.insert(insertionIndex, elementToInsert);
    }

	std::cout << "After: ";
	for (size_t i = 0; i < s.size(); i++)
		std::cout << s[i] << " ";
	std::cout << std::endl;
}

std::vector<unsigned int>::iterator PmergeMe::binarySearchInsertionIndex(std::vector<unsigned int> &s, unsigned int element)
{
	// (void) element;
    std::vector<unsigned int>::iterator low = s.begin();
    std::vector<unsigned int>::iterator high = s.end();
    while (low != high)
	{
        std::vector<unsigned int>::iterator mid = low + (high - low) / 2;
        if (*mid < element)
            low = mid + 1;
		else
            high = mid;
    }
    return (low);
}

long long currentTimeMicros() {
    timeval currentTime;
    gettimeofday(&currentTime, NULL);
    return currentTime.tv_sec * 1000000LL + currentTime.tv_usec;
}

void	PmergeMe::mergeInsertSort(int argc, char **argv)
{
	long long startTime = currentTimeMicros();

	// clock_t startTime = std::clock();
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

	long long endTime = currentTimeMicros();
	long long elapsedTime = endTime - startTime;
	hasDuplicate(pairs, hasStraggler);
	startTime = currentTimeMicros();
	sortPairs(pairs);
	sortLargerValue(pairs, pairs.size());
	FMJI(pairs, hasStraggler);
	endTime = currentTimeMicros();
	endTime = elapsedTime + (endTime - startTime);


	std::cout << "Time to process a range of " << argc - 1 << " elements with std:: vector : ";
	std::cout << std::fixed;
	std::cout << endTime << " us" << std::endl;
    startTime = currentTimeMicros();
	sortPairsList(list);
	sortLargerValueList(list, list.size());
	// for (std::list<std::pair<unsigned int, unsigned int> >::iterator it = list.begin(); it != list.end(); it++)
	// {
	// 	std::cout << " " << it->first << " " << it->second << std::endl;
	// 	// if (pairs[i].first > pairs[i].second)
	// 	// 	std::swap(pairs[i].first, pairs[i].second);
	// }
	FMJIlist(list, hasStraggler);
	endTime = currentTimeMicros();
	endTime = elapsedTime + (endTime - startTime);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std:: list : ";
	std::cout << std::fixed;
	std::cout << endTime << " us" << std::endl;

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
		{
			// std::cout << "hyhy" << std::endl;
			std::swap(*it, *ite);
		}
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
   		// std::cout <<"pipi = " << it->first;
    	// std::cout << "lala = " << it->second << std::endl;
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
	// std::cout << "After: ";
	// for (std::list<unsigned int>::iterator it = s.begin(); it != s.end(); it++)
	// 	std::cout << *it << " ";
	// std::cout << std::endl;
}

std::list<unsigned int>::iterator PmergeMe::binarySearchInsertionIndexList(std::list<unsigned int> &s, unsigned int element)
{

	std::list<unsigned int>::iterator it = s.begin();

    while (it != s.end() && *it < element)
	{
        ++it;
    }

    return it;
}
