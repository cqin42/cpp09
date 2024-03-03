#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <utility>
#include <typeinfo>
#include <sys/time.h>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		PmergeMe(const PmergeMe &autre);
		PmergeMe &operator=(const PmergeMe &autre);
		~PmergeMe();

		void	mergeInsertSort(int argc, char **argv);
		void	sortPairs(std::vector<std::pair<unsigned int, unsigned int> > &pairs);
		void	sortLargerValue(std::vector<std::pair<unsigned int, unsigned int> > &pairs, int n);
		void	FMJI(std::vector<std::pair<unsigned int, unsigned int> > &pairs, int straggler);
		void	insertPend(std::vector<unsigned int> &s, const std::vector<unsigned int> &pend);
		std::vector<unsigned int>::iterator	binarySearchInsertionIndex(std::vector<unsigned int> &s, unsigned int element);

		// size_t	binarySearchInsertionIndexList(std::list<unsigned int> &s, unsigned int element);
		std::list<unsigned int>::iterator	binarySearchInsertionIndexList(std::list<unsigned int> &s, unsigned int element);
		void	insertPendList(std::list<unsigned int> &s, const std::list<unsigned int> &pend);
		void	FMJIlist(std::list<std::pair<unsigned int, unsigned int> > &pairs, int straggler);
		void	sortLargerValueList(std::list<std::pair<unsigned int, unsigned int> > &pairs, int n);
		void	sortPairsList(std::list<std::pair<unsigned int, unsigned int> > &pairs);

};

template<typename T>
void	hasDuplicate(const T &sequence, int surplus)
{
	T tmp = sequence;

	typedef typename T::const_iterator Iterator;
	Iterator it = tmp.begin();
	typedef typename T::value_type valueType;
	valueType n = *it;
	for (it = tmp.begin() + 1 ; it != tmp.end(); it++)
	{
		for (Iterator ite = it ; ite != tmp.end(); ite++)
		{
			if (n.first == ite->first || n.first == ite->second || n.first == n.second)
				throw std::runtime_error("Error: duplicate integer");
			else if (n.second == ite->first || n.second == ite->second)
				throw std::runtime_error("Error: duplicate integer");
			else if (surplus != -1 && ((unsigned int)surplus == n.first || (unsigned int)surplus == n.second))
				throw std::runtime_error("Error: duplicate integer");
		}
		n = *it;
	}

	std::cout << "Before: ";
	for (it = tmp.begin() ; it != tmp.end(); it++)
	{
		std::cout << it->first << " " << it->second << " ";
	}
	if (surplus != -1)
		std::cout << surplus;
	std::cout << std::endl;
}

#endif
