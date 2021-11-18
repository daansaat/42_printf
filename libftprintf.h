/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libftprintf.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/15 16:53:48 by dsaat         #+#    #+#                 */
/*   Updated: 2021/11/16 17:26:45 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_print
{
	va_list		args;
	int			char_count;
}				t_print;

int		ft_printf(const char *fmt, ...);
void	ft_print_char(t_print *data);
void	ft_print_str(t_print *data);
void	ft_print_ptr_hex(t_print *data);
void	ft_print_nbr(t_print *data);
void	ft_print_nbr_unsigned(t_print *data);
void	ft_print_nbr_hex(t_print *data, int caps);

#endif
