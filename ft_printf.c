/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/15 16:59:53 by dsaat         #+#    #+#                 */
/*   Updated: 2021/11/18 12:20:59 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
static void	ft_convert_fmt(t_print *data, char c);

int	ft_printf(const char *fmt, ...)
{
	t_print	*data;

	data = malloc(sizeof(t_print));
	if (!data)
		return (0);
	data->char_count = 0;
	va_start(data->args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			ft_convert_fmt(data, *(fmt + 1));
			fmt++;
		}
		else
			data->char_count += write(1, fmt, 1);
		fmt++;
	}
	va_end(data->args);
	free(data);
	return (data->char_count);
}

static void	ft_convert_fmt(t_print *data, char c)
{	
	if (c == 'c')
		ft_print_char(data);
	else if (c == 's')
		ft_print_str(data);
	else if (c == 'p')
		ft_print_ptr_hex(data);
	else if (c == 'i' || c == 'd')
		ft_print_nbr(data);
	else if (c == 'u')
		ft_print_nbr_unsigned(data);
	else if (c == 'x')
		ft_print_nbr_hex(data, 0);
	else if (c == 'X')
		ft_print_nbr_hex(data, 1);
	else if (c == '%')
		data->char_count += write(1, "%%", 1);
	else
		data->char_count += write(1, &c, 1);
}
