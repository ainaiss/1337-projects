#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <list>
#include <vector>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:
		MutantStack(void) : std::stack<T, Container>() {}
		MutantStack(const MutantStack &other): std::stack<T, Container>(other){};
		MutantStack &operator=(MutantStack const &rhs)
		{
			this->c = rhs.c;
			return (*this);
		}
		typedef typename std::stack<T, Container>::container_type::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end() ;}
};

#endif
