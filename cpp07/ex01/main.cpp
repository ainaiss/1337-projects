#include "iter.hpp"

template<typename T>
void	_print(T const &c)
{
	std::cout << c;
}

template<typename T>
void	_up(T const &c)
{
	std::cout << (char)toupper(c);
}

int main()
{
	char str[] = {'a', 'b', 'c', 'd', 'e', 'f', 'j'};
	iter(str, 4, _print);
	std::cout << std::endl;
	iter(str, 4, &_up);
	std::cout << std::endl;
	for (int i = 0; i < str[i]; i++)
		std::cout << str[i];
	std::cout << std::endl;
}
