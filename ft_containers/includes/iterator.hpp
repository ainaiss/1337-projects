/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:53:29 by fel-boua          #+#    #+#             */
/*   Updated: 2022/11/02 21:37:03 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cstddef>
#include "AVL.hpp"

namespace ft
{
	template <class Iterator>
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type difference_type;
			typedef typename Iterator::value_type value_type;
			typedef typename Iterator::pointer pointer;
			typedef typename Iterator::reference reference;
			typedef typename Iterator::iterator_category iterator_category;
	};
	
	template <class T>
	class iterator_traits<T *>
	{
		public:
			typedef ptrdiff_t diffrence_type;
			typedef T value_type;
			typedef T *pointer;
			typedef T &reference;
			typedef std::random_access_iterator_tag iterator_category;
	};
	
	template <class T>
	class iterator_traits<const T *>
	{
		public:
			typedef ptrdiff_t diffrence_type;
			typedef T value_type;
			typedef const T *pointer;
			typedef const T &reference;
			typedef std::random_access_iterator_tag iterator_category;
	};


	template<class Iterator>
	class reverse_iterator
	{
		public:
			
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef typename iterator_traits<Iterator>::value_type			value_type;
			typedef typename iterator_traits<Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<Iterator>::pointer				pointer;
			typedef typename iterator_traits<Iterator>::reference			reference;
		

			
			reverse_iterator() {}
			explicit reverse_iterator (iterator_type it): _it(it) {}
			template <class Iter>
			reverse_iterator (const reverse_iterator<Iter>& rev_it){_it = rev_it.base();}
			~reverse_iterator() {}
		
			iterator_type base() const { return (_it);}
			
			reference operator*() const { return *(--Iterator(_it)); }
		
			reverse_iterator operator+ (difference_type n) const {
				return (reverse_iterator(_it - n));
			}
			reverse_iterator operator- (difference_type n) const {
				return (reverse_iterator(_it + n));
			}
			//pre increment
			reverse_iterator& operator++()
			{
				_it--;
				return (*this);
			}
			//post increment
			reverse_iterator  operator++(int)
			{
				reverse_iterator tmp = *this;
				++(*this);
				return (tmp);
			}
			// post
			reverse_iterator  operator--(int)
			{
				reverse_iterator tmp = *this;
				--(*this);
				return (tmp);
			}
			//pre
			reverse_iterator& operator--()
			{
				_it++;
				return (*this);
			}
			reverse_iterator& operator+= (difference_type n)
			{
				_it -= n;
				return (*this);
			}
			reverse_iterator& operator-= (difference_type n)
			{
				_it += n;
				return (*this);
			}
			//accesses the pointed-to element
			pointer operator->() const {return &(operator*());}
			reference operator[] (difference_type n) const { return (base()[-n-1]);}
	
		private:
			iterator_type _it;
	};
	

	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
	{return (lhs.base() == rhs.base());}
	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
	{return (lhs.base() != rhs.base());}
	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
	{return (lhs.base() > rhs.base());}
	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
	{return (lhs.base() >= rhs.base());}
	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
	{return (lhs.base() < rhs.base());}
	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs,
					const reverse_iterator<Iterator>& rhs)
	{return (lhs.base() <= rhs.base());}
	template <class Iterator>
	reverse_iterator<Iterator> operator+(
		typename reverse_iterator<Iterator>::difference_type n,
		const reverse_iterator<Iterator> &rev_it)
	{
		return (reverse_iterator<Iterator>(rev_it.base() - n));
	}
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(
		const reverse_iterator<Iterator> &lhs,
		const reverse_iterator<Iterator> &rhs)
	{
		return (rhs.base() - lhs.base());
	}
	
	template<typename T>
	class random_access_iterator
	{
		public:
			
			typedef T											value_type;
			typedef std::random_access_iterator_tag				iterator_category;
			typedef T*											pointer;
			typedef T&											reference;
			typedef ptrdiff_t									difference_type;
			
			//Constructors 	X a; X b(a); b = a;
			random_access_iterator(): _it(NULL) {}
			explicit random_access_iterator(value_type *it): _it(it) {}
			random_access_iterator(random_access_iterator const &src) {*this = src;}
			random_access_iterator& operator=(random_access_iterator const &src)
			{
				_it = src._it;
				return (*this);
			}
			~random_access_iterator() {}
			
			reference operator*() const { return (*_it);}
			pointer operator->() const {return &(operator*());}
			reference operator[] (difference_type n) const { return (_it[n]);}
			pointer base() const{return (_it);}
			
			bool operator==(const random_access_iterator<T>& src){
				return (_it == src._it);
			}
			bool operator!=(const random_access_iterator<T>& src){
				return (_it != src._it);
			}
			random_access_iterator &operator++()
			{
				_it++;
				return (*this);
			}
			random_access_iterator operator++(int)
			{
				random_access_iterator tmp = *this;
				++(*this);
				return (tmp);
			}
			random_access_iterator &operator--()
			{
				_it--;
				return (*this);
			}
			random_access_iterator operator--(int)
			{
				random_access_iterator tmp = *this;
				--(*this);
				return (tmp);
			}
			random_access_iterator& operator+= (difference_type n)
			{
				_it += n;
				return (*this);
			}
			random_access_iterator& operator-= (difference_type n)
			{
				_it -= n;
				return (*this);
			}
			random_access_iterator operator+ (difference_type n) const {
				return (random_access_iterator(_it + n));
			}
			random_access_iterator operator- (difference_type n) const {
				return (random_access_iterator(_it - n));
			}
			operator random_access_iterator<const T>() const {
				return (random_access_iterator<const T>(_it));
			}
		private:
			pointer _it;
	};

	template <class Iterator>
	bool operator==(const random_access_iterator<Iterator> &lhs, const random_access_iterator<Iterator> &rhs)
	{
		return (lhs.base() == rhs.base());
	}
	template <class Iterator>
	bool operator!=(const random_access_iterator<Iterator> &lhs,
		const random_access_iterator<Iterator> &rhs)
	{
		return (lhs.base() != rhs.base());
	}
	template <class Iterator>
	bool operator<(const random_access_iterator<Iterator> &lhs,
			const random_access_iterator<Iterator> &rhs)
	{
		return (lhs.base() < rhs.base());
	}
	template <class Iterator>
	bool operator<=(const random_access_iterator<Iterator> &lhs,
		const random_access_iterator<Iterator> &rhs)
	{
		return (lhs.base() <= rhs.base());
	}
	template <class Iterator>
	bool operator>(const random_access_iterator<Iterator> &lhs,
		const random_access_iterator<Iterator> &rhs)
	{
		return (lhs.base() > rhs.base());
	}
	template <class Iterator>
	bool operator>=(const random_access_iterator<Iterator> &lhs,
		const random_access_iterator<Iterator> &rhs)
	{
		return (lhs.base() >= rhs.base());
	}
	template <class Iterator>
	random_access_iterator<Iterator> operator+(
		typename random_access_iterator<Iterator>::difference_type n,
		const random_access_iterator<Iterator> &rev_it)
	{
		return (random_access_iterator<Iterator>(rev_it.base() + n));
	}
	template <class Iterator>
	typename random_access_iterator<Iterator>::difference_type operator-(
		const random_access_iterator<Iterator> &lhs,
		const random_access_iterator<Iterator> &rhs)
	{
		return (lhs.base() - rhs.base());
	}
	
    
	template <typename T, typename Compare, typename Alloc>
	class bidirectional_iterator
	{
		public:
			typedef T                               value_type; // DRY
			typedef int                             difference_type;
			typedef T*                              pointer;
			typedef T&                              reference;
			typedef std::bidirectional_iterator_tag iterator_category;
			bidirectional_iterator(pointer ptr, const AVL<value_type, Compare, Alloc>* avl = NULL)
			: _ptr(ptr), _avl(avl){};
			bidirectional_iterator(): _ptr(NULL) {}
			~bidirectional_iterator(){}
			bidirectional_iterator&  operator=(const bidirectional_iterator& bid_it)
			{
				_ptr = bid_it._ptr;
				_avl = bid_it._avl;
				return (*this);
			}
			operator bidirectional_iterator<const T, Compare, Alloc> () const { return bidirectional_iterator<const T, Compare, Alloc>(_ptr, reinterpret_cast<const AVL<const value_type, Compare, Alloc>*>(_avl)); }
			bidirectional_iterator& operator++()
			{
			
				AvlNode<value_type, Alloc> *node = _avl->find(_avl->root, *_ptr);
				if (node)
				{
					AvlNode<value_type, Alloc> *succ = _avl->successor(*_ptr);
					if (succ)
						_ptr = succ->data;
					else
						_ptr = NULL;
				}
				return (*this);
			}
			bidirectional_iterator operator++(int)
			{
				bidirectional_iterator i = *this;
				++(*this);
				return i;
			}
			bidirectional_iterator& operator--()
			{
				
				AvlNode<value_type, Alloc> *node = NULL;
				if (!_ptr)
				{
					node = _avl->findMax(_avl->root);
					if (node)
						_ptr = node->data;
					return (*this);
				}
				node = _avl->find(_avl->root, *_ptr);
				if (node)
				{
					AvlNode<value_type, Alloc> *succ = _avl->predecessor(*_ptr);
					if (succ)
						_ptr = succ->data;
					else
						_ptr = NULL;
				}
				return (*this);
			}
			bidirectional_iterator operator--(int)
			{
				bidirectional_iterator i = *this;
				--(*this);
				return i;
			}
			difference_type operator-(bidirectional_iterator src)const { return (_ptr - src._ptr);}
			reference operator*()const { return *_ptr;}
			pointer operator->() const{ return _ptr;}
			friend bool operator== (const bidirectional_iterator& lhs, const bidirectional_iterator& rhs)
			{
				return (lhs._ptr == rhs._ptr);
			}
			friend bool operator!= (const bidirectional_iterator& lhs, const bidirectional_iterator& rhs)
			{
				return !(lhs == rhs);
			}
		public:
			pointer _ptr;
			const AVL<value_type, Compare, Alloc>* _avl;
	};
}