/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:53:22 by fel-boua          #+#    #+#             */
/*   Updated: 2022/11/02 02:22:31 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template <class T1, class T2>
	class pair
	{
		public:
	
			T1 first;
			T2 second;

		
			typedef T1 first_type;
			typedef T2 second_type;
	

			
			pair(): first(first_type()), second(second_type()) {}

			//copy
			template<class U, class V> 
			pair (const pair<U,V>& pr): first(pr.first), second(pr.second){}

			//initi
			pair (const first_type& a, const second_type& b): first(a), second(b) {}

			/*** operator= ***/
			pair& operator= (const pair& pr)
			{
				first = pr.first;
				second = pr.second;
				return (*this);
			}
	};
	//Construct pair object 
	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return (pair<T1, T2>(x,y));
	}
	/** Non-member function overloads **/
	// when  we compare two pair we compare the first of lhs with the first of rhs and the second also the same
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}

	template <class T1, class T2>
	bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs == rhs);
	}

	template <class T1, class T2>
	bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (rhs < lhs);
	}

	template <class T1, class T2>
	bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs < rhs);
	}
}
