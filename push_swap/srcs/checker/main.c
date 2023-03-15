/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:22:55 by fel-boua          #+#    #+#             */
/*   Updated: 2021/11/14 19:11:28 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/checker.h"

int	main(int ac, char **av)
{
	char		*line;
	t_stacks	stacks;
	char		*string;
	int			ret;

	ac--;
	if (ac == 0)
		return (0);
	string = ft_av_to_string(av);
	stacks = ft_store_numbers(string);
	line = NULL;
	ret = 0;
	while (get_next_line(0, &line) == 1)
	{
		ft_select_instruction(line, &stacks);
		free(line);
	}
	free(line);
	if (ft_issorted(&stacks.stack_a) && !stacks.stack_b.used_size)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	return (ft_put_err(&stacks, NULL, 0));
}
