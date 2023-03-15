#include "span.hpp"

int main()
{
	{
		try{
			Span sp = Span(5);
			sp.addNumber(5);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	std::cout << "_____________test2_____________\n";
	{
		try
		{
			Span sp = Span(10000);
			for (int i = 1; i <= 5000; i++)
				sp.addNumber(i);
			std::vector<int> vec[500];
			for(int i = 5001; i <= 10000; i++)
				vec->push_back(i);
			sp.addNumber(vec->begin(), vec->end());
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	return (0);
}
