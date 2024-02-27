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


	private:
		// std::vector<unsigned int> vector;
		// std::list<unsigned int> list;
		// int idx;
};

template<typename T>
void	hasDuplicate(const T &sequence)
{
	T tmp = sequence;

	std::sort(tmp.begin(), tmp.end());
	typename T::iterator it = tmp.begin();
	typename T::value_type n = *it;
	for (it = tmp.begin() + 1 ; it != tmp.end(); it++)
	{
		if (n == *it)
			throw std::runtime_error("Error: duplicate integer");
		n = *it;
	}
}


#endif
