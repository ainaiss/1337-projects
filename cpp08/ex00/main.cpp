#include "easyfind.hpp"


int main()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	easyfind(vec, 1100);



	std::cout << "______________________\n";



	
	std::list<int> list;
	list.push_back(10);
	list.push_back(20);
	list.push_back(30);
	list.push_back(40);
	easyfind(list, 20);
}