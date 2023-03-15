#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
	unsigned int _N;
	std::vector<int> _vec;
public:
	Span(){};
	Span(unsigned int n);
	~Span(){};
	void	addNumber(unsigned int n);
	unsigned int		shortestSpan();
	unsigned int		longestSpan();
	template<typename T>
	void	addNumber(T a, T b)
	{
		int dis = std::distance(a, b);
		if (dis + _vec.size() <= _N)
		//vector_name.insert(position, iterator1, iterator2)
			_vec.insert(_vec.end(), a, b);								//returns an iterator which points to the newly inserted element
		else
			throw FullContainer();
	}

	class OutOfRange : public std::exception
	{
		const char * what() const throw()
		{
			return "Number already exist!!";
		}
	};
	class NoSpan : public std::exception
	{
		const char * what() const throw()
		{
			return "There is no span to find!!";
		}
	};
	class FullContainer : public std::exception
	{
		const char *what() const throw(){
			return ("Full container");
		}
	};
};

#endif
