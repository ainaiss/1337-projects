#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>

class OutOfRange : public std::exception
{
	const char * what() const throw()
	{
		return "This number not exist!!";
	}
};

template<typename T>
void	easyfind(T t, int n)
{
	try{
		if ((std::find(t.begin(), t.end(), n)) != t.end())
			std::cout << "Number " << n << " EXIST" << std::endl;
		else
			throw OutOfRange();
	}catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

#endif
