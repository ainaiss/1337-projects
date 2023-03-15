#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <stdio.h>

template<typename T>
void	iter(T *array, int length, void (*fun)(T const &c))
{
	for (int i = 0; i < length; i++)
		fun(array[i]);
}

#endif
