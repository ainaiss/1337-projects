/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 02:03:10 by fel-boua          #+#    #+#             */
/*   Updated: 2022/11/03 02:28:47 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once
#include <iostream>

namespace ft
{
	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2, BinaryPredicate pred)
	{
		while (first1 != last1)
		{
			if (!pred(*first1, *first2))
				return (false);
			first1++;
			first2++;
		}
		return (true);
	}
	
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			// so its greater or null return false
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			first1++;
			first2++;
		}
		return (first2 != last2);
	}
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2,
									Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return (false);
			else if (comp(*first1 , *first2))
				return (true);
			first1++;
			first2++;
		}
		return (first2 != last2);
	}
 
	template <bool Cond, class T = void>
	struct enable_if {};

	template<class T> 
	struct enable_if<true, T> { typedef T type; };
	

	template<class T, T v>
	struct integral_constant
	{
		static const T value = v;
		typedef T value_type;
		typedef integral_constant<T, v> type;
		operator T() {return (v);}
	};
	template <class T> struct is_integral: public integral_constant<bool, false> {};
	template<> struct is_integral<bool>: public integral_constant<bool, true> {} ;
	template<> struct is_integral<char>: public integral_constant<bool, true> {} ;
	template<> struct is_integral<wchar_t>: public integral_constant<bool, true> {} ;
	template<> struct is_integral<signed char>: public integral_constant<bool, true> {} ;
	template<> struct is_integral<short int>: public integral_constant<bool, true> {} ;
	template<> struct is_integral<int>: public integral_constant<bool, true> {} ;
	template<> struct is_integral<long int>: public integral_constant<bool, true> {} ;
	template<> struct is_integral<long long int>: public integral_constant<bool, true> {} ;
	template<> struct is_integral<unsigned char>: public integral_constant<bool, true> {} ;
	template<> struct is_integral<unsigned short int>: public integral_constant<bool, true> {} ;
	template<> struct is_integral<unsigned int>: public integral_constant<bool, true> {} ;
	template<> struct is_integral<unsigned long int>: public integral_constant<bool, true> {} ;
	template<> struct is_integral<unsigned long long int>: public integral_constant<bool, true> {} ;
}
