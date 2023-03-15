/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:53:25 by fel-boua          #+#    #+#             */
/*   Updated: 2022/11/02 02:16:30 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <memory>
#include <iostream>
#include <sstream>
#include <cstddef>
#include <deque>
#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef T value_type;
			typedef Container container_type;
			typedef size_t size_type;
			explicit stack (const container_type& ctnr = container_type()): _ctnr(ctnr){}
			~stack(void) {};
			bool empty() const { return (_ctnr.empty());}
			size_type size() const {return (_ctnr.size()); }
			value_type& top()
			{
				return (_ctnr.back());
			}
			const value_type& top() const
			{
				return (_ctnr.back());
			}
			void push (const value_type& val)
			{
				_ctnr.push_back(val);
			}
			void pop()
			{
				_ctnr.pop_back();
			}
		protected:
			container_type _ctnr;
		private:
			// we use friend because we cant access the attributes from external class 
            //A friend function is a function that can access the private members of a class as though it were a member of that class
			template <class A, class B>
			friend bool operator== (const stack<A,B>& lhs, const stack<A,B>& rhs);
			template <class A, class B>
			friend bool operator!= (const stack<A,B>& lhs, const stack<A,B>& rhs);
			template <class A, class B>
			friend bool operator< (const stack<A,B>& lhs, const stack<A,B>& rhs);
			template <class A, class B>
			friend bool operator<= (const stack<A,B>& lhs, const stack<A,B>& rhs);
			template <class A, class B>
			friend bool operator> (const stack<A,B>& lhs, const stack<A,B>& rhs);
			template <class A, class B>
			friend bool operator>= (const stack<A,B>& lhs, const stack<A,B>& rhs);
	};
	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._ctnr == rhs._ctnr);
	}

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._ctnr != rhs._ctnr);
	}

	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._ctnr < rhs._ctnr);
	}

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._ctnr <= rhs._ctnr);
	}

	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._ctnr > rhs._ctnr);
	}

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs._ctnr >= rhs._ctnr);
	}
}