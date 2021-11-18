/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/15 17:00:23 by dsaat         #+#    #+#                 */
/*   Updated: 2021/11/16 12:48:05 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
static size_t	ft_strlen(const char *str);

void	ft_print_str(t_print *data)
{
	char	*str;
	int		len;

	str = va_arg(data->args, char *);
	if (!str)
	{
		data->char_count += write(1, "(null)", 6);
		return ;
	}
	len = ft_strlen(str);
	data->char_count += write(1, str, len);
}

static size_t	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	while (str[n] != '\0')
		n++;
	return (n);
}
