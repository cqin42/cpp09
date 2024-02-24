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

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &autre);
		PmergeMe &operator=(const PmergeMe &autre);
		~PmergeMe();
	private:
		std::vector<unsigned int> vector;
		std::list<unsigned int> list;
		int idx;
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
// template<typename T>
// void	printSequence(const T &sequence, std::string str)
// {
// 	typename T::const_iterator it;;
// 	std::cout << str + ":	";
// 	for (it = sequence.begin(); it != sequence.end(); it++)
// 	{
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;
// }
// template<typename T>
// T	mergeInsert1(T sequence1, T sequence2)
// {
// 	T	sorted;

// 	typename T::iterator it1 = sequence1.begin();
// 	typename T::iterator it2 = sequence2.begin();

// 	while (it1 != sequence1.end() && it2 != sequence2.end())
// 	{
// 		if (*it1 > *it2)
// 		{
// 			sorted.push_back(*it2);
// 			it2++;
// 		}
// 		else
// 		{
// 			sorted.push_back(*it1);
// 			it1++;
// 		}
// 	}

// 	while(it1 != sequence1.end())
// 	{
// 		sorted.push_back(*it1);
// 		it1++;
// 	}

// 	while(it2 != sequence2.end())
// 	{
// 		sorted.push_back(*it2);
// 		it2++;
// 	}
// 	sequence1.clear();
// 	sequence2.clear();

// 	return (sorted);
// }

// template<typename T>
// T	mergeInsert(T sequence)
// {
// 	T sequence1;

// 	if (sequence.size() <= 1)
// 		return (sequence);

// 	int half = ceil(static_cast<float>(sequence.size()) / 2);
// 	for (int i = 0; i < half; i++)
// 	{
// 		sequence1.push_back(sequence.front());
// 		sequence.erase(sequence.begin());
// 	}
// 	sequence1 = mergeInsert(sequence1);
// 	sequence = mergeInsert(sequence);
// 	return (mergeInsert1(sequence1, sequence));
// }


// template<typename T>
// void	mergeInsertSortProgram(T &sequence, std::string type)
// {
// 	// printSequence(sequence, "Before");
// 	clock_t startTime = std::clock();
// 	sequence = mergeInsert(sequence);
// 	if (type == "vector")
// 		printSequence(sequence, "After");
// 	clock_t end = std::clock();
// 	std::cout << "Time to process a range of " << sequence.size();
// 	std::cout << " elements with std::" << type << " : ";
// 	std::cout << static_cast<double>(end - startTime)/ static_cast<double>(CLOCKS_PER_SEC) * 1000000 << " ms" << std::endl;
// }


#endif
