#include "mutantstack.hpp"

int main()
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl; //access the element at the top of the stack container
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
		std::cout << *it << std::endl;
		++it;
		}
		std::cout << "_____________________\n";
		std::stack<int> s(mstack);
		while (!s.empty())
		{
			std::cout << s.top() << std::endl;
			s.pop();
		}
	}
	std::cout << "_____________________\n";
	{
		MutantStack<std::string> mstack;
		typedef MutantStack<std::string>::iterator iterator;
		mstack.push("ABCD");
		mstack.push("12345");
		mstack.push("EFJ");
		mstack.push("678910");
		iterator it = mstack.begin();
		iterator it2 = mstack.end();
		while (it != it2)
		{
			std::cout << *it << std::endl;
			it++;
		}
	}
	{
		std::vector<int> vec;
	}
	return 0;
}
