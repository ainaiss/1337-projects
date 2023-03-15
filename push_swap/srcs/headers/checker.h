/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:23:31 by fel-boua          #+#    #+#             */
/*   Updated: 2021/11/14 19:12:33 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include "../get_next_line/get_next_line.h"

void	ft_select_instruction(char *line, t_stacks *stacks);
void	ft_print(t_stacks *stacks);
void	ft_print_stack_b(t_stacks *stacks);
void	ft_print_stack_a(t_stacks *stacks);
#endif