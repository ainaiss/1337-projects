#include "span.hpp"

Span::Span(unsigned int n): _N(n)
{
	_vec.reserve(n);
}

void	Span::addNumber(unsigned int n)
{
	if (_vec.size() < _N)
		_vec.push_back(n);
	else
		throw OutOfRange();
}

unsigned int Span::longestSpan()
{
	if (_vec.size() > 1)
		return *std::max_element(_vec.begin(), _vec.end())
			- *std::min_element(_vec.begin(), _vec.end());
	else
		throw NoSpan();
}

unsigned int Span::shortestSpan()
{
	if (_vec.size() <= 1)
		throw NoSpan();
	std::vector<int> sort = _vec;
	std::sort(sort.begin(), sort.end());
	int min = sort[1] - sort[0];
	for (unsigned int i = 1; i < sort.size() - 1; i++)
		if (sort[i + 1] - sort[i] < min)
			min = sort[i + 1] - sort[i];
	return min;
}
