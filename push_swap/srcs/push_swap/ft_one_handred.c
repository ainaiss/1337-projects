/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_handred.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:27:10 by fel-boua          #+#    #+#             */
/*   Updated: 2021/11/14 19:14:47 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

int	ft_search_index(t_stacks *stacks, int key_number)
{
	int	i;

	i = 0;
	while (i < stacks->stack_a.used_size)
	{
		if (stacks->stack_a.vector[i] <= key_number)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_move_to_top(t_stacks *stacks, int index)
{
	int	divid;

	divid = stacks->stack_a.used_size / 2;
	while (index != 0)
	{
		if (index <= divid)
		{
			ft_rotate_a(&stacks->stack_a, YES);
			index--;
		}
		else
		{
			ft_reverse_rotate_a(&stacks->stack_a, YES);
			index++;
			if (index == stacks->stack_a.used_size)
				break ;
		}
	}
}

void	ft_push_index(t_stacks *stacks, int key_number)
{
	int	index;

	index = ft_search_index(stacks, key_number);
	while (index != -1)
	{
		ft_move_to_top(stacks, index);
		ft_push_b(stacks, YES);
		index = ft_search_index(stacks, key_number);
	}
}

void	ft_one_handred(t_stacks *stacks)
{
	int	i;
	int	key_number;
	int	*sorted_list;

	i = 1;
	sorted_list = ft_sort_array(&stacks->stack_a);
	while (i != 4)
	{
		key_number = ft_find_key_number(sorted_list,
				stacks->stack_a.size, i, 4);
		ft_push_index(stacks, key_number);
		i++;
	}
	free (sorted_list);
	ft_sort_rest(stacks);
	while (stacks->stack_b.used_size != 0)
	{
		ft_find_biggest_number(stacks);
		ft_push_a(stacks, YES);
	}
}

void	ft_five_handred(t_stacks *stacks)
{
	int	i;
	int	key_number;
	int	*sorted_list;

	i = 1;
	sorted_list = ft_sort_array(&stacks->stack_a);
	while (i != 8)
	{
		key_number = ft_find_key_number(sorted_list,
				stacks->stack_a.size, i, 8);
		ft_push_index(stacks, key_number);
		i++;
	}
	free (sorted_list);
	ft_sort_more_then_handred(stacks);
	while (stacks->stack_b.used_size != 0)
	{
		ft_find_biggest_number(stacks);
		ft_push_a(stacks, YES);
	}
}
