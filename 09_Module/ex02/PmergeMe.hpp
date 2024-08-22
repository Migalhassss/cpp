#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <ctime>
#include <iomanip>
#include <stdexcept>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

class PmergeMe {

private:

	std::vector<int> vec;
	std::deque<int> deq;
	static const int jacobsthal[35];
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &rhs);
	void sortAndPrint(int argc, char* argv[]);
	template <typename Container>
	void fordJohnsonSort(Container& container);

	template <typename Container>
	void binaryJacobsthalInsert(Container& base, const Container& merge);

	template <typename Container>
	Container generateJacobsthalNumbers(int n);

	template <typename Container>
	typename Container::iterator findInsertionPoint(Container& base, const typename Container::value_type& value);

	template <typename Container>
	void printContainer(const Container& container, const std::string& label);
	
	int calculateCurrentIndex(int index);

	template <typename Container>
	typename Container::iterator findInsertionPoint(Container& base, const Container& merge, int current);

	template <typename Container>
	void insertElementAtPoint(Container& base, typename Container::iterator where, const Container& merge, int current);

	int* generateJacobsthalSequence(int n);

};

template <typename Container>
void PmergeMe::printContainer(const Container& container, const std::string& name) {
	std::cout << name << ": ";
	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

#endif // PMERGEME_HPP