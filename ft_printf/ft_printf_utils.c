/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <fel-boua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:49:23 by fel-boua          #+#    #+#             */
/*   Updated: 2020/12/26 16:53:18 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_data(t_data *s)
{
	s->flag = 0;
	s->max = 0;
	s->min = 0;
	s->prec = 0;
	s->type = 0;
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

t_data	ft_set_type(t_data *s, char c)
{
	s->type = (c == 's') ? 0 : s->type;
	s->type = (c == 'd' || c == 'i') ? 1 : s->type;
	s->type = (c == 'x') ? 2 : s->type;
	s->type = (c == 'X') ? 3 : s->type;
	s->type = (c == 'c') ? 4 : s->type;
	s->type = (c == 'p') ? 5 : s->type;
	s->type = (c == 'u') ? 6 : s->type;
	s->type = (c == '%') ? 7 : s->type;
	return (*s);
}

t_data	check_form(const char **str)
{
	t_data s;

	init_data(&s);
	while (**str != 's' && **str != 'd' && **str != 'c' && **str != 'x'
			&& **str != 'X' && **str != 'i' && **str != 'p'
			&& **str != 'u' && **str != '%')
	{
		s.flag = (**str == '0' && *(*str - 1) == '%') ? -1 : s.flag;
		s.prec = (**str == '.') ? 1 : s.prec;
		s.flag = (**str == '-') ? 1 : s.flag;
		if (**str == '*')
		{
			if (s.prec == 0)
				s.min = -1;
			else
				s.max = -1;
		}
		else if (**str >= '0' && **str <= '9' && s.prec == 0)
			s.min = s.min * 10 + **str - 48;
		else if (**str >= '0' && **str <= '9' && s.prec == 1)
			s.max = s.max * 10 + **str - 48;
		(*str)++;
	}
	return (ft_set_type(&s, **str));
}

void	ft_printf_sub(t_data s, va_list *lst, int *cpt)
{
	if (s.type == 0)
		affiche_s(lst, s, cpt);
	if (s.type == 1)
		affiche_d(lst, s, cpt);
	if (s.type == 2 || s.type == 3)
		affiche_x(lst, s, s.type, cpt);
	if (s.type == 4)
		affiche_c(lst, s, cpt);
	if (s.type == 5)
		affiche_p(lst, s, cpt);
	if (s.type == 6)
		affiche_u(lst, s, cpt);
	if (s.type == 7)
		display_perc(lst, s, cpt);
}
