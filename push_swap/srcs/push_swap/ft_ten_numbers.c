/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:30:54 by fel-boua          #+#    #+#             */
/*   Updated: 2021/11/14 17:30:58 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	ft_find_smallest_number_ten(t_stacks *stacks)
{
	int	s_index;

	s_index = ft_get_smallest_index(&stacks->stack_a);
	while (s_index != 0)
	{
		if (s_index <= 5)
			ft_rotate_a(&stacks->stack_a, YES);
		else
			ft_reverse_rotate_a(&stacks->stack_a, YES);
		s_index = ft_get_smallest_index(&stacks->stack_a);
	}
}

void	ft_sort_ten_numbers(t_stacks *stacks)
{
	if (!ft_issorted(&stacks->stack_a))
	{
		while (stacks->stack_a.used_size != 5)
		{
			ft_find_smallest_number_ten(stacks);
			ft_push_b(stacks, YES);
		}
		ft_sort_five_numbers(stacks);
		while (stacks->stack_a.used_size != stacks->stack_a.size)
			ft_push_a(stacks, YES);
	}
}
