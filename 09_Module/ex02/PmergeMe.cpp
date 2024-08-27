#include "PmergeMe.hpp"
#include <iostream>


// Constructor
PmergeMe::PmergeMe() {}

// Destructor
PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &src) {
	if (this == &src) {
		return *this;
	}
	vec = src.vec;
	deq = src.deq;
	return *this;
}

const int PmergeMe::jacobsthal[35] = {
	-1, 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923,
	21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405,
	11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883,
	1431655765};

template <typename Container>
void PmergeMe::printContainer(const Container& container, const std::string& name) {
	std::cout << name << ": ";
	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int PmergeMe::calculateCurrentIndex(int index) {
	return jacobsthal[index] - 1;
}

template <typename Container>
typename Container::iterator PmergeMe::findInsertionPoint(Container& base, const Container& merge, int current) {
	return std::lower_bound(base.begin(), base.end(), merge[current]);
}

template <typename Container>
void PmergeMe::insertElementAtPoint(Container& base, typename Container::iterator where, const Container& merge, int current) {
	base.insert(where, merge[current]);
}

template <typename Container>
void PmergeMe::binaryJacobsthalInsert(Container& base, const Container& merge) {
	typename Container::iterator it;
	int current = merge.size() - 1;
	int jacobsthalIndex = 1;

	while (current >= 0) {
		if (current == calculateCurrentIndex(jacobsthalIndex)) {
			it = findInsertionPoint(base, merge, current);
			insertElementAtPoint(base, it, merge, current);
			--current;
			jacobsthalIndex = 1;
		} else {
			it = findInsertionPoint(base, merge, current);
			insertElementAtPoint(base, it, merge, current);
			++jacobsthalIndex;
			--current;
		}
	}
}

template <typename Container>
void PmergeMe::fordJohnsonSort(Container& container) {

	Container copy;
	Container smaller;
	size_t size = container.size() - 1;

	if (container.size() < 2) return;
	copy = container;
	container.clear();

	for (size_t i = 0; i < size;) {
		if (copy[i] > copy[i + 1]) {
			container.push_back(copy[i]);
			smaller.push_back(copy[i + 1]);
		} else {
			container.push_back(copy[i + 1]);
			smaller.push_back(copy[i]);
		}
		i += 2;
	}

	if (copy.size() % 2 != 0) {
		container.push_back(copy[size]);
	}
	fordJohnsonSort(container);
	binaryJacobsthalInsert(container, smaller);
}

void PmergeMe::sortAndPrint(int argc, char* argv[]) {
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <numbers>" << std::endl;
		return;
	}


	for (int i = 1; i < argc; ++i) {
		int num = std::atoi(argv[i]);
		vec.push_back(num);
		deq.push_back(num);
	}

	//check is already sorted
	bool sorted = true;
	for (size_t i = 0; i < vec.size() - 1; ++i) {
		if (vec[i] > vec[i + 1]) {
			sorted = false;
		}
	}
	if (sorted) {
		std::cout << "Already sorted" << std::endl;
		return ;
	}	



	std::cout << "Before: ";
	printContainer(vec, "");

	clock_t start, end;
	double vec_duration, deq_duration;

	start = clock();
	fordJohnsonSort(vec);
	end = clock();
	vec_duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

	start = clock();
	fordJohnsonSort(deq);
	end = clock();
	deq_duration = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1e6;

	std::cout << "After: ";
	printContainer(vec, "");

	std::cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << std::fixed << std::setprecision(5) << vec_duration << " us" << std::endl;
	std::cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << std::fixed << std::setprecision(5) << deq_duration << " us" << std::endl;
	
}