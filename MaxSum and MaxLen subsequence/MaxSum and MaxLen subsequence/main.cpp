#include <iostream>
#include <vector>
#include <list>

namespace maxsubsequence
{

template<class TValue>
TValue getMax(std::vector<typename TValue> sumVect)
{
	auto it = sumVect.begin();
	TValue max = *it++;

	for (; it != sumVect.end(); ++it)
	{
		if (*it > max)
		{
			max = *it;
		}
	}

	return max;
}

template<typename Iterator, class TValue = typename Iterator::value_type>
TValue getMaxLenIS(const Iterator begin, const Iterator end)
{
	if (begin == end)
	{
		return {};
	}

	std::vector<TValue> maxLen{ 1 };
	std::vector<TValue> temp{ 1 };

	auto i = begin;
	++i;

	for (; i != end; ++i)
	{
		size_t k = 0;
		for (auto j = begin; j != i; ++j)
		{
			if (*i > *j)
			{
				auto it = maxLen.begin();
				std::advance(it, k++);
				temp.emplace_back(*it + 1);
			}
		}
		maxLen.emplace_back(getMax(temp));
	}

	return getMax(maxLen);
}

template<typename Iterator, class TValue = typename Iterator::value_type>
TValue getMaxSumIS(const Iterator begin, const Iterator end)
{
	if (begin == end)
	{
		return {};
	}

	std::vector<TValue> maxSum{ *begin };
	std::vector<TValue> temp{ *begin };

	auto i = begin;
	++i;

	for (; i != end; ++i)
	{
		size_t k = 0;
		for (auto j = begin; j != i; ++j)
		{
			if (*i > *j)
			{
				auto it = maxSum.begin();
				std::advance(it, k++);
				temp.emplace_back(*it + *i);
			}
		}
		maxSum.emplace_back(getMax(temp));
	}

	return getMax(maxSum);
}

}//namespace maxsubsequence

int main()
{
	std::vector<int> vect{ 5, 4, 7, 2, 1, 9, 7, 8, 10 };
	std::list<double> l{ 5, 4, 3, 2, 1 };

	std::cout << maxsubsequence::getMaxLenIS(vect.begin(), vect.end()) << std::endl;
	std::cout << maxsubsequence::getMaxLenIS(l.begin(), l.end()) << std::endl;

	std::cout << maxsubsequence::getMaxSumIS(vect.begin(), vect.end()) << std::endl;
	std::cout << maxsubsequence::getMaxSumIS(l.begin(), l.end()) << std::endl;
}
