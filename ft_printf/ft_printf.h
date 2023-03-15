/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-boua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/24 10:53:06 by fel-boua          #+#    #+#             */
/*   Updated: 2020/12/24 10:53:09 by fel-boua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_data
{
	int flag;
	int prec;
	int min;
	int max;
	int type;
}				t_data;
void			ft_putstr(char *s);
char			*ft_strdup(char *s);
int				ft_atoi(char *s);
void			affichec(int min, char c, int flag, int *cpt);
void			affiche1_s(int min, int max, char *s, int *cpt);
void			affiche2_s(int min, char *s, int *cpt);
void			affiche3_s(t_data t, char *s, int *cpt, char c);
void			affiche4_s(int min, char *s, int *cpt, char c);
void			affiche_s(va_list *p, t_data s, int *cpt);
int				numberofdigits(unsigned int n);
char			*convertetohex(unsigned int n, int j);
void			ft_fill_pos(char *str, int size, long long int nb);
void			ft_fill_neg(char *str, int size, long long int nb);
long long int	ft_abs(long long int nb);
char			*ft_itoa(int n);
int				ft_strlen(char *str);
void			init_t_data(t_data *s);
t_data			check_form(const char **str);
void			affiche_d(va_list *p, t_data s, int *cpt);
void			affiche_d_sub(t_data s, char *st, int n, int *cpt);
void			affiche1_d(int min, int max, char *s, int *cpt);
void			affiche2_d(int min, char *s, int *cpt);
void			affiche3_d(int min, int max, char *s, int *cpt);
void			affiche4sub_d(int min, char *s, int len, int *cpt);
void			affiche4_d(int min, char *s, int n, int *cpt);
void			affiche_c(va_list *p, t_data s, int *cpt);
int				ft_printf(const char *str, ...);
void			affiche1_x(int min, int max, char *s, int *cpt);
void			affiche2_x(int min, char *s, int *cpt);
void			affiche3_x(int min, int max, char *s, int *cpt);
void			affiche4_sub_x(int min, char *s, int len, int *cpt);
void			affiche4_x(int min, char *s, int *cpt);
void			affiche_x(va_list *p, t_data s, int j, int *cpt);
void			affiche_x_sub(t_data s, char *st, int *cpt);
void			affiche_u(va_list *p, t_data s, int *cpt);
void			affiche_u_sub(t_data s, char *st, int *cpt);
void			affiche1_u(int min, int max, char *s, int *cpt);
void			affiche2_u(int min, char *s, int *cpt);
void			affiche3_u(int min, int max, char *s, int *cpt);
void			affiche4_sub_u(int min, char *s, int len, int *cpt);
void			affiche4_u(int min, char *s, int *cpt);
char			*ft_itoa_u(unsigned int n);
void			affiche_p(va_list *p, t_data s, int *cpt);
void			affiche_p_sub(t_data s, char *st, int *cpt);
char			*convertetohex_p(unsigned long dec);
int				numberofdigits_p(unsigned long n);
void			affiche1_p(int min, int max, char *s, int *cpt);
void			affiche2_p(int min, char *s, int *cpt);
void			affiche3_p(int min, int max, char *s, int *cpt);
void			affiche4sub_p(int min, char *s, int len, int *cpt);
void			affiche4_p(int min, char *s, int *cpt);
t_data			ft_set_type(t_data *s, char c);
void			ft_putchar(char c);
void			display_perc(va_list *lst, t_data s, int *cpt);
void			ft_printf_sub(t_data s, va_list *lst, int *cpt);

#endif
